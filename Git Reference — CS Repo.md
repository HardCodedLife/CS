# Git Reference — CS Repo

## Setup

### Clone repo
```bash
git clone https://github.com/HardCodedLife/CS.git
```

### Or link existing local folder
```bash
git remote add origin https://github.com/HardCodedLife/CS.git
git push -u origin main
```

### Embed token in URL (avoid credential prompts)
```bash
git remote set-url origin https://<username>:<token>@github.com/HardCodedLife/CS.git
```

---

## Config

### Identity (for commit display only)
```bash
git config --global user.name "Your Name"
git config --global user.email "you@example.com"
```

### Set vim as default editor
```bash
git config --global core.editor vim
```

### Add to ~/.bashrc for system-wide vim default
```bash
export VISUAL=vim
export EDITOR=vim
```

---

## Daily Workflow

```bash
git status                  # check what changed
git add .                   # stage all changes
git add <file>              # stage specific file
git commit                  # opens vim: write title + description
git push origin main        # push to GitHub
git pull origin main        # pull latest from GitHub
```

---

## Commit Message Format

```
[Phase][Week] Short title under 50 chars

- Detail what was added or changed
- What still needs to be done
- Any bugs fixed
```

### Examples
```
[OS][W1] Add memory layout visualizer

- Print addresses of global, local, heap, and function
- Shows why each address is high or low
- TODO: add stack growth demonstration
```
```
[OS][W3] Implement tiny shell

- Add fork() and exec() for command execution
- Add wait() to handle child process completion
- TODO: handle piping between commands
```
```
[NET][W1] Add basic HTTP client

- Open raw TCP socket
- Send HTTP GET request manually
- Print raw response
```

---

## PROGRESS.md Template

```markdown
# CS Study Progress

## Phase 1 — OS (OSTEP) `Month 1–2`

### Week 1–2 | Processes & Address Space
- [ ] Memory layout visualizer

### Week 3–4 | Processes & System Calls
- [ ] Tiny shell (fork, exec, wait)

### Week 5–6 | Threads & Concurrency
- [ ] Multithreaded word counter

### Week 7–8 | Virtual Memory
- [ ] my_malloc() clone

---

## Phase 2 — Networking (Top-Down Approach) `Month 3–4`

### Week 1–2 | Application Layer
- [ ] Tiny HTTP client in C

### Week 3–4 | Transport Layer
- [ ] TCP chat program

### Week 5–6 | Network Layer
- [ ] traceroute clone

### Week 7–8 | TLS / HTTPS
- [ ] Upgrade HTTP client to HTTPS (OpenSSL)

---

## Phase 3 — Architecture (Patterson & Hennessy) `Month 5–6`

### Week 1–2 | ISA
- [ ] Assembly inspector

### Week 3–4 | Memory Hierarchy & Cache
- [ ] Cache behavior demonstrator (matrix multiplication)

### Week 5–6 | Pipelining
- [ ] Branch prediction experiment

### Week 7–8 | I/O & Interrupts
- [ ] DMA & interrupt observer (strace)
```

---

## GitHub Token (Fine-grained)

- **Location:** GitHub → Settings → Developer Settings → Fine-grained tokens
- **Repository access:** Select only `CS` repo
- **Permissions needed:**
  - `Contents`: Read and Write ✅
  - `Metadata`: Read-only ✅ (auto-selected)

> Renew token before expiry or push will return 403.

---

## Makefile — Output to bin/

```makefile
bin/:
	mkdir -p bin

cpu: bin/ cpu.c common.h
	gcc -o bin/cpu cpu.c -Wall
```

---

## .gitignore Key Rules

- `bin/` — ignores all `bin/` folders recursively
- `*.o` — compiled object files
- `*.a`, `*.so` — libraries
- `*.exe`, `*.out` — executables with extensions

---

## Useful Commands

```bash
git log --oneline           # compact commit history
git log --oneline --graph   # with branch visualization
git diff                    # see unstaged changes
git restore <file>          # discard local changes to a file
git stash                   # temporarily save uncommitted changes
```
