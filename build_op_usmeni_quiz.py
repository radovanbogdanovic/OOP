from __future__ import annotations

import html
import json
import random
import re
import xml.etree.ElementTree as ET
from pathlib import Path
from zipfile import ZipFile


SOURCE = Path("op usmeni.docx")
OUTPUT = Path("op_usmeni_quiz.html")

W_NS = "http://schemas.openxmlformats.org/wordprocessingml/2006/main"
TEXT = f"{{{W_NS}}}t"
TAB = f"{{{W_NS}}}tab"
BR = f"{{{W_NS}}}br"
P = f"{{{W_NS}}}p"
QUESTION_RE = re.compile(r"^\s*(\d{1,3})\s*[\.:]\s*(.*)")
CHOICE_PREVIEW_LIMIT = 320


def extract_paragraphs(path: Path) -> list[str]:
    with ZipFile(path) as docx:
        root = ET.fromstring(docx.read("word/document.xml"))

    paragraphs: list[str] = []
    for paragraph in root.findall(f".//{P}"):
        parts: list[str] = []
        for node in paragraph.iter():
            if node.tag == TEXT:
                parts.append(node.text or "")
            elif node.tag == TAB:
                parts.append("\t")
            elif node.tag == BR:
                parts.append("\n")
        text = "".join(parts).strip()
        if text:
            paragraphs.append(text)
    return paragraphs


def parse_questions(paragraphs: list[str]) -> list[dict[str, object]]:
    items: list[dict[str, object]] = []
    current: dict[str, object] | None = None

    for paragraph in paragraphs:
        match = QUESTION_RE.match(paragraph)
        if match:
            if current is not None:
                items.append(current)
            current = {
                "number": int(match.group(1)),
                "question": match.group(2).strip(),
                "answer": [],
            }
        elif current is not None:
            current["answer"].append(paragraph)

    if current is not None:
        items.append(current)

    for item in items:
        answer_lines = item["answer"]
        if not isinstance(answer_lines, list):
            answer_lines = []
        item["answer"] = "\n".join(str(line) for line in answer_lines).strip()
        if not item["answer"]:
            item["answer"] = "Nema odgovora u dokumentu."

    return items


def answer_preview(answer: object) -> str:
    text = re.sub(r"\s+", " ", str(answer)).strip()
    if len(text) <= CHOICE_PREVIEW_LIMIT:
        return text
    shortened = text[:CHOICE_PREVIEW_LIMIT].rsplit(" ", 1)[0].rstrip(".,;:")
    return f"{shortened}..."


def add_choices(items: list[dict[str, object]]) -> None:
    pool = [(index, answer_preview(item["answer"])) for index, item in enumerate(items)]

    for index, item in enumerate(items):
        seed = int(item["number"]) * 7919 + index
        rng = random.Random(seed)
        correct = answer_preview(item["answer"])
        options = [{"text": correct, "correct": True}]
        used = {correct}
        candidates = [candidate for candidate in pool if candidate[0] != index]
        rng.shuffle(candidates)

        for _, preview in candidates:
            if preview in used:
                continue
            options.append({"text": preview, "correct": False})
            used.add(preview)
            if len(options) == 4:
                break

        rng.shuffle(options)
        item["choices"] = options


def build_html(items: list[dict[str, object]]) -> str:
    numbers = {int(item["number"]) for item in items}
    missing = [n for n in range(1, 101) if n not in numbers]
    missing_text = ", ".join(str(n) for n in missing) if missing else "none"
    missing_note = (
        f"Dokument ima {len(items)} ucitanih pitanja. Nedostaje broj: {missing_text}."
        if missing
        else f"Dokument ima {len(items)} ucitanih pitanja."
    )
    no_answer_count = sum(1 for item in items if item["answer"] == "Nema odgovora u dokumentu.")

    add_choices(items)
    data = json.dumps(items, ensure_ascii=False)
    safe_note = html.escape(missing_note)

    return f"""<!doctype html>
<html lang="sr">
<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>OP Usmeni Quiz</title>
  <style>
    :root {{
      color-scheme: light;
      --paper: #f7f4ee;
      --ink: #1f2526;
      --muted: #647174;
      --line: #d8d1c4;
      --surface: #ffffff;
      --surface-2: #edf3f1;
      --accent: #176b87;
      --accent-2: #bb4d3e;
      --ok: #1f7a53;
      --warn: #a66500;
      --shadow: 0 18px 45px rgba(31, 37, 38, .12);
    }}

    * {{ box-sizing: border-box; }}

    body {{
      margin: 0;
      min-height: 100vh;
      background:
        linear-gradient(180deg, rgba(255,255,255,.62), rgba(255,255,255,.1)),
        var(--paper);
      color: var(--ink);
      font: 16px/1.5 system-ui, -apple-system, BlinkMacSystemFont, "Segoe UI", sans-serif;
    }}

    button,
    input,
    textarea {{
      font: inherit;
    }}

    button {{
      border: 1px solid transparent;
      background: var(--surface);
      color: var(--ink);
      cursor: pointer;
      transition: transform .15s ease, border-color .15s ease, background .15s ease;
    }}

    button:hover {{ transform: translateY(-1px); }}
    button:active {{ transform: translateY(0); }}
    button:disabled {{
      cursor: not-allowed;
      opacity: .6;
      transform: none;
    }}

    .app {{
      width: min(1180px, calc(100vw - 32px));
      margin: 0 auto;
      padding: 22px 0 40px;
    }}

    .topbar {{
      display: grid;
      grid-template-columns: 1fr auto;
      gap: 16px;
      align-items: center;
      padding-bottom: 18px;
    }}

    .title h1 {{
      margin: 0;
      font-size: clamp(1.6rem, 3vw, 2.45rem);
      line-height: 1.05;
      letter-spacing: 0;
    }}

    .title p {{
      margin: 7px 0 0;
      color: var(--muted);
    }}

    .stats {{
      display: grid;
      grid-template-columns: repeat(4, minmax(82px, 1fr));
      gap: 8px;
      min-width: min(460px, 100%);
    }}

    .stat {{
      border: 1px solid var(--line);
      background: rgba(255, 255, 255, .78);
      padding: 10px 12px;
      min-height: 64px;
    }}

    .stat strong {{
      display: block;
      font-size: 1.25rem;
      line-height: 1.1;
    }}

    .stat span {{
      color: var(--muted);
      font-size: .82rem;
    }}

    .toolbar {{
      display: grid;
      grid-template-columns: minmax(220px, 1fr) auto;
      gap: 12px;
      align-items: center;
      border-top: 1px solid var(--line);
      border-bottom: 1px solid var(--line);
      padding: 12px 0;
      margin-bottom: 18px;
    }}

    .search {{
      width: 100%;
      min-height: 44px;
      border: 1px solid var(--line);
      background: rgba(255, 255, 255, .86);
      color: var(--ink);
      padding: 0 13px;
      outline: none;
    }}

    .search:focus {{
      border-color: var(--accent);
      box-shadow: 0 0 0 3px rgba(23, 107, 135, .14);
    }}

    .tabs,
    .actions,
    .grade-actions {{
      display: flex;
      gap: 8px;
      flex-wrap: wrap;
      align-items: center;
    }}

    .tab,
    .button {{
      min-height: 40px;
      padding: 0 13px;
      border-color: var(--line);
      border-radius: 7px;
      white-space: nowrap;
    }}

    .tab.active,
    .button.primary {{
      background: var(--accent);
      border-color: var(--accent);
      color: #fff;
    }}

    .button.danger {{
      background: #fff2ef;
      border-color: #efc3bb;
      color: #8b2d20;
    }}

    .button.ok {{
      background: #eff8f3;
      border-color: #bedfce;
      color: #176340;
    }}

    .main {{
      display: grid;
      grid-template-columns: minmax(0, 1fr) 300px;
      gap: 20px;
      align-items: start;
    }}

    .panel,
    .side {{
      background: rgba(255, 255, 255, .88);
      border: 1px solid var(--line);
      box-shadow: var(--shadow);
    }}

    .panel {{
      min-height: 560px;
      padding: clamp(18px, 3vw, 32px);
    }}

    .side {{
      padding: 16px;
      position: sticky;
      top: 14px;
    }}

    .progress {{
      height: 10px;
      background: #e6e0d5;
      overflow: hidden;
      margin-bottom: 18px;
    }}

    .progress span {{
      display: block;
      height: 100%;
      width: 0%;
      background: linear-gradient(90deg, var(--accent), var(--ok));
      transition: width .2s ease;
    }}

    .meta {{
      display: flex;
      justify-content: space-between;
      gap: 10px;
      color: var(--muted);
      font-size: .95rem;
      margin-bottom: 14px;
    }}

    .badge {{
      display: inline-flex;
      align-items: center;
      min-height: 28px;
      padding: 0 10px;
      border: 1px solid var(--line);
      background: var(--surface-2);
      color: #385155;
      border-radius: 999px;
      font-size: .84rem;
      white-space: nowrap;
    }}

    .question {{
      margin: 0;
      font-size: clamp(1.45rem, 2.2vw, 2.25rem);
      line-height: 1.18;
      letter-spacing: 0;
    }}

    .answer {{
      margin-top: 26px;
      padding: 22px;
      border-left: 5px solid var(--accent);
      background: #f5faf8;
      white-space: pre-wrap;
      font-size: 1.05rem;
    }}

    .answer.hidden {{
      display: none;
    }}

    .choice-list {{
      display: grid;
      gap: 10px;
      margin-top: 24px;
    }}

    .choice {{
      width: 100%;
      min-height: 64px;
      border-color: var(--line);
      border-radius: 8px;
      padding: 13px 15px;
      text-align: left;
      line-height: 1.42;
      white-space: normal;
    }}

    .choice:hover {{
      border-color: var(--accent);
      background: #f7fbfa;
    }}

    .choice:disabled {{
      cursor: default;
      opacity: 1;
    }}

    .choice:disabled:hover {{
      transform: none;
    }}

    .choice.selected {{
      border-color: var(--accent);
      box-shadow: 0 0 0 3px rgba(23, 107, 135, .12);
    }}

    .choice.correct {{
      border-color: #82c69f;
      background: #eef8f2;
    }}

    .choice.wrong {{
      border-color: #eba89f;
      background: #fff1ee;
    }}

    .choice-label {{
      display: inline-flex;
      align-items: center;
      justify-content: center;
      width: 26px;
      height: 26px;
      margin-right: 8px;
      border-radius: 50%;
      background: var(--surface-2);
      color: var(--accent);
      font-weight: 800;
      vertical-align: top;
    }}

    .feedback {{
      margin-top: 16px;
      padding: 12px 14px;
      border: 1px solid var(--line);
      background: #fff;
      color: #314044;
    }}

    .feedback.correct {{
      border-color: #82c69f;
      background: #eef8f2;
      color: #176340;
    }}

    .feedback.wrong {{
      border-color: #eba89f;
      background: #fff1ee;
      color: #8b2d20;
    }}

    .typebox {{
      width: 100%;
      min-height: 150px;
      margin-top: 24px;
      padding: 14px;
      border: 1px solid var(--line);
      background: #fff;
      resize: vertical;
      outline: none;
    }}

    .typebox:focus {{
      border-color: var(--accent);
      box-shadow: 0 0 0 3px rgba(23, 107, 135, .14);
    }}

    .card-actions {{
      display: flex;
      justify-content: space-between;
      gap: 12px;
      flex-wrap: wrap;
      margin-top: 24px;
    }}

    .side h2 {{
      margin: 0 0 12px;
      font-size: 1rem;
    }}

    .number-grid {{
      display: grid;
      grid-template-columns: repeat(5, 1fr);
      gap: 6px;
      margin-bottom: 16px;
    }}

    .num {{
      aspect-ratio: 1;
      border-radius: 6px;
      border-color: var(--line);
      padding: 0;
      min-width: 0;
      font-size: .85rem;
    }}

    .num.active {{
      background: var(--accent);
      border-color: var(--accent);
      color: #fff;
    }}

    .num.known {{
      border-color: #91c8ac;
      background: #eef8f2;
    }}

    .num.review {{
      border-color: #e0b471;
      background: #fff6e8;
    }}

    .num.active.known,
    .num.active.review {{
      background: var(--accent);
      color: #fff;
    }}

    .note {{
      border-top: 1px solid var(--line);
      padding-top: 12px;
      color: var(--muted);
      font-size: .92rem;
    }}

    .browse {{
      display: grid;
      gap: 10px;
    }}

    details {{
      border: 1px solid var(--line);
      background: rgba(255, 255, 255, .88);
      padding: 0;
    }}

    summary {{
      cursor: pointer;
      padding: 13px 15px;
      font-weight: 700;
    }}

    details div {{
      border-top: 1px solid var(--line);
      padding: 14px 15px 16px;
      white-space: pre-wrap;
      color: #314044;
    }}

    .empty {{
      color: var(--muted);
      padding: 22px;
      border: 1px dashed var(--line);
      background: rgba(255, 255, 255, .6);
    }}

    @media (max-width: 860px) {{
      .topbar,
      .toolbar,
      .main {{
        grid-template-columns: 1fr;
      }}

      .stats {{
        grid-template-columns: repeat(2, minmax(0, 1fr));
        min-width: 0;
      }}

      .side {{
        position: static;
      }}
    }}

    @media (max-width: 520px) {{
      .app {{
        width: min(100vw - 20px, 1180px);
        padding-top: 12px;
      }}

      .tabs,
      .actions,
      .grade-actions,
      .card-actions {{
        display: grid;
        grid-template-columns: 1fr 1fr;
      }}

      .button,
      .tab {{
        width: 100%;
      }}

      .number-grid {{
        grid-template-columns: repeat(6, 1fr);
      }}
    }}
  </style>
</head>
<body>
  <main class="app">
    <section class="topbar">
      <div class="title">
        <h1>OP Usmeni Quiz</h1>
        <p>{safe_note}</p>
      </div>
      <div class="stats" aria-label="Progress">
        <div class="stat"><strong id="totalStat">{len(items)}</strong><span>pitanja</span></div>
        <div class="stat"><strong id="knownStat">0</strong><span>znam</span></div>
        <div class="stat"><strong id="reviewStat">0</strong><span>ponovi</span></div>
        <div class="stat"><strong id="leftStat">0</strong><span>ostalo</span></div>
      </div>
    </section>

    <section class="toolbar">
      <input id="search" class="search" type="search" placeholder="Pretraga ili broj pitanja" autocomplete="off">
      <div class="tabs" role="tablist" aria-label="Rezim">
        <button class="tab active" data-mode="study" type="button">Kartice</button>
        <button class="tab" data-mode="test" type="button">Ponuđeni odgovori</button>
        <button class="tab" data-mode="browse" type="button">Sva pitanja</button>
      </div>
    </section>

    <section class="main">
      <article class="panel" id="panel"></article>
      <aside class="side">
        <h2>Mapa pitanja</h2>
        <div class="number-grid" id="numberGrid"></div>
        <div class="actions">
          <button class="button" id="shuffleBtn" type="button">Promesaj</button>
          <button class="button" id="resetBtn" type="button">Reset</button>
        </div>
        <p class="note">Pitanje 40 ne postoji u dokumentu. {no_answer_count} pitanje nema tekst odgovora.</p>
      </aside>
    </section>
  </main>

  <script>
    const QUESTIONS = {data};
    const STORAGE_KEY = 'op-usmeni-quiz-progress-v1';

    const state = {{
      mode: 'study',
      order: QUESTIONS.map((_, index) => index),
      currentPosition: 0,
      revealed: false,
      selectedChoice: null,
      checked: false,
      query: '',
      progress: loadProgress()
    }};

    const panel = document.getElementById('panel');
    const numberGrid = document.getElementById('numberGrid');
    const search = document.getElementById('search');
    const totalStat = document.getElementById('totalStat');
    const knownStat = document.getElementById('knownStat');
    const reviewStat = document.getElementById('reviewStat');
    const leftStat = document.getElementById('leftStat');

    function loadProgress() {{
      try {{
        return JSON.parse(localStorage.getItem(STORAGE_KEY)) || {{}};
      }} catch {{
        return {{}};
      }}
    }}

    function saveProgress() {{
      localStorage.setItem(STORAGE_KEY, JSON.stringify(state.progress));
    }}

    function escapeText(value) {{
      return String(value)
        .replaceAll('&', '&amp;')
        .replaceAll('<', '&lt;')
        .replaceAll('>', '&gt;')
        .replaceAll('"', '&quot;')
        .replaceAll("'", '&#039;');
    }}

    function currentIndex() {{
      return state.order[state.currentPosition] ?? 0;
    }}

    function currentQuestion() {{
      return QUESTIONS[currentIndex()];
    }}

    function resetInteraction() {{
      state.revealed = false;
      state.selectedChoice = null;
      state.checked = false;
    }}

    function optionLetter(index) {{
      return String.fromCharCode(65 + index);
    }}

    function renderChoices(item) {{
      return `<div class="choice-list">${{item.choices.map((choice, index) => {{
        const selected = state.selectedChoice === index;
        const correct = choice.correct;
        const classes = ['choice'];
        if (selected) classes.push('selected');
        if (state.checked && correct) classes.push('correct');
        if (state.checked && selected && !correct) classes.push('wrong');
        return `<button class="${{classes.join(' ')}}" type="button" data-choice="${{index}}" ${{state.checked ? 'disabled' : ''}}>
          <span class="choice-label">${{optionLetter(index)}}</span>${{escapeText(choice.text)}}
        </button>`;
      }}).join('')}}</div>`;
    }}

    function renderFeedback(item) {{
      if (!state.checked) return '';
      const selected = item.choices[state.selectedChoice];
      const correct = selected && selected.correct;
      const text = correct
        ? 'Tacno. Mozes oznaciti da znas ili preci na sledece pitanje.'
        : 'Nije tacno. Pogledaj oznacen tacan odgovor i puno resenje ispod.';
      return `<div class="feedback ${{correct ? 'correct' : 'wrong'}}">${{text}}</div>`;
    }}

    function filteredIndexes() {{
      const query = state.query.trim().toLowerCase();
      if (!query) return QUESTIONS.map((_, index) => index);
      return QUESTIONS
        .map((item, index) => ({{ item, index }}))
        .filter((entry) => {{
          const haystack = `${{entry.item.number}} ${{entry.item.question}} ${{entry.item.answer}}`.toLowerCase();
          return haystack.includes(query);
        }})
        .map((entry) => entry.index);
    }}

    function setMode(mode) {{
      state.mode = mode;
      resetInteraction();
      document.querySelectorAll('.tab').forEach((tab) => {{
        tab.classList.toggle('active', tab.dataset.mode === mode);
      }});
      render();
    }}

    function setStatus(number, status) {{
      const key = String(number);
      if (state.progress[key] === status) {{
        delete state.progress[key];
      }} else {{
        state.progress[key] = status;
      }}
      saveProgress();
      render();
    }}

    function autoGradeCurrentQuestion() {{
      if (state.mode !== 'test' || !state.checked || state.selectedChoice === null) return;
      const item = currentQuestion();
      const selected = item.choices[state.selectedChoice];
      state.progress[String(item.number)] = selected && selected.correct ? 'known' : 'review';
      saveProgress();
    }}

    function go(delta) {{
      const total = state.order.length;
      if (delta > 0) autoGradeCurrentQuestion();
      state.currentPosition = (state.currentPosition + delta + total) % total;
      resetInteraction();
      render();
    }}

    function jumpToIndex(index) {{
      const position = state.order.indexOf(index);
      state.currentPosition = position >= 0 ? position : 0;
      resetInteraction();
      setMode('study');
    }}

    function shuffle() {{
      for (let i = state.order.length - 1; i > 0; i -= 1) {{
        const j = Math.floor(Math.random() * (i + 1));
        [state.order[i], state.order[j]] = [state.order[j], state.order[i]];
      }}
      state.currentPosition = 0;
      resetInteraction();
      render();
    }}

    function resetProgress() {{
      state.progress = {{}};
      saveProgress();
      render();
    }}

    function renderStats() {{
      const values = Object.values(state.progress);
      const known = values.filter((value) => value === 'known').length;
      const review = values.filter((value) => value === 'review').length;
      totalStat.textContent = String(QUESTIONS.length);
      knownStat.textContent = String(known);
      reviewStat.textContent = String(review);
      leftStat.textContent = String(Math.max(QUESTIONS.length - known, 0));
    }}

    function renderNumberGrid() {{
      numberGrid.innerHTML = QUESTIONS.map((item, index) => {{
        const status = state.progress[String(item.number)] || '';
        const active = index === currentIndex() && state.mode !== 'browse' ? ' active' : '';
        return `<button class="num ${{status}}${{active}}" type="button" data-index="${{index}}" title="Question ${{item.number}}">${{item.number}}</button>`;
      }}).join('');
    }}

    function renderCard(testMode = false) {{
      const item = currentQuestion();
      const progress = Math.round(((state.currentPosition + 1) / state.order.length) * 100);
      const status = state.progress[String(item.number)];
      const answerClass = state.revealed ? 'answer' : 'answer hidden';
      const choices = testMode
        ? renderChoices(item)
        : '';
      const feedback = testMode ? renderFeedback(item) : '';
      const checkButton = testMode && !state.checked
        ? `<button class="button primary" id="checkBtn" type="button" ${{state.selectedChoice === null ? 'disabled' : ''}}>Proveri</button>`
        : '';
      const gradeButtons = state.revealed || state.checked
        ? `<div class="grade-actions">
            <button class="button ok" type="button" data-status="known">Znam</button>
            <button class="button danger" type="button" data-status="review">Ponovi</button>
          </div>`
        : '';

      panel.innerHTML = `
        <div class="progress"><span style="width: ${{progress}}%"></span></div>
        <div class="meta">
          <span>Pitanje ${{item.number}}</span>
          <span class="badge">${{state.currentPosition + 1}} / ${{state.order.length}}${{status ? ' · ' + status : ''}}</span>
        </div>
        <h2 class="question">${{escapeText(item.question)}}</h2>
        ${{choices}}
        ${{feedback}}
        <div id="answer" class="${{answerClass}}">${{escapeText(item.answer)}}</div>
        <div class="card-actions">
          <div class="actions">
            <button class="button" id="prevBtn" type="button">Nazad</button>
            <button class="button" id="nextBtn" type="button">Sledece</button>
          </div>
          <div class="actions">
            ${{checkButton}}
            <button class="button primary" id="revealBtn" type="button">${{state.revealed ? 'Sakrij resenje' : 'Prikazi resenje'}}</button>
            ${{gradeButtons}}
          </div>
        </div>
      `;
    }}

    function renderBrowse() {{
      const matches = filteredIndexes();
      if (matches.length === 0) {{
        panel.innerHTML = '<div class="empty">No matches.</div>';
        return;
      }}
      panel.innerHTML = `<div class="browse">${{matches.map((index) => {{
        const item = QUESTIONS[index];
        return `<details>
          <summary>${{item.number}}. ${{escapeText(item.question)}}</summary>
          <div>${{escapeText(item.answer)}}</div>
        </details>`;
      }}).join('')}}</div>`;
    }}

    function render() {{
      renderStats();
      renderNumberGrid();
      if (state.mode === 'browse') {{
        renderBrowse();
      }} else {{
        renderCard(state.mode === 'test');
      }}
    }}

    document.querySelectorAll('.tab').forEach((tab) => {{
      tab.addEventListener('click', () => setMode(tab.dataset.mode));
    }});

    document.getElementById('shuffleBtn').addEventListener('click', shuffle);
    document.getElementById('resetBtn').addEventListener('click', resetProgress);

    numberGrid.addEventListener('click', (event) => {{
      const button = event.target.closest('button[data-index]');
      if (!button) return;
      jumpToIndex(Number(button.dataset.index));
    }});

    panel.addEventListener('click', (event) => {{
      const target = event.target.closest('button');
      if (!target) return;
      if (target.dataset.choice !== undefined) {{
        state.selectedChoice = Number(target.dataset.choice);
        render();
        return;
      }}
      if (target.id === 'prevBtn') go(-1);
      if (target.id === 'nextBtn') go(1);
      if (target.id === 'checkBtn' && state.selectedChoice !== null) {{
        state.checked = true;
        state.revealed = true;
        render();
      }}
      if (target.id === 'revealBtn') {{
        state.revealed = !state.revealed;
        render();
      }}
      if (target.dataset.status) {{
        setStatus(currentQuestion().number, target.dataset.status);
      }}
    }});

    search.addEventListener('input', () => {{
      state.query = search.value;
      const numeric = Number(state.query.trim());
      const exact = QUESTIONS.findIndex((item) => item.number === numeric);
      if (exact >= 0 && state.mode !== 'browse') {{
        jumpToIndex(exact);
        return;
      }}
      render();
    }});

    document.addEventListener('keydown', (event) => {{
      if (event.target.matches('input, textarea')) return;
      if (event.key === 'ArrowLeft') go(-1);
      if (event.key === 'ArrowRight') go(1);
      if (event.key === ' ') {{
        event.preventDefault();
        state.revealed = !state.revealed;
        render();
      }}
    }});

    render();
  </script>
</body>
</html>
"""


def main() -> None:
    if not SOURCE.exists():
        raise SystemExit(f"Missing source file: {SOURCE}")
    items = parse_questions(extract_paragraphs(SOURCE))
    OUTPUT.write_text(build_html(items), encoding="utf-8")
    numbers = {int(item["number"]) for item in items}
    missing = [n for n in range(1, 101) if n not in numbers]
    no_answer = [item["number"] for item in items if item["answer"] == "Nema odgovora u dokumentu."]
    print(f"Wrote {OUTPUT}")
    print(f"Parsed questions: {len(items)}")
    print(f"Missing numbers: {missing or 'none'}")
    print(f"No-answer questions: {no_answer or 'none'}")


if __name__ == "__main__":
    main()
