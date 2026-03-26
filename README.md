# CS
Learning about Computer Science

---

**Phase 1 Build Path — OS (paired with OSTEP)**

---

**Week 1–2 | Reading: Processes & Address Space**
Build: **A memory layout visualizer in C**
```c
// Print the address of: a global var, a local var, 
// a heap-allocated var, and a function
// Then explain WHY each address is high or low
```
Goal: *See* the memory layout you just read about. Make it real.

---

**Week 3–4 | Reading: Processes & System Calls**
Build: **A tiny shell in C**
- Accept a command like `ls` or `pwd`
- Use `fork()` and `exec()` to run it
- Wait for it to finish with `wait()`

Goal: Understand that every program you've ever run was launched this way.

---

**Week 5–6 | Reading: Threads & Concurrency**
Build: **A multithreaded word counter**
- Split a large text file into chunks
- Count words in parallel using threads
- Handle the race condition when summing results

Goal: Feel the pain of concurrency bugs firsthand.

---

**Week 7–8 | Reading: Virtual Memory**
Build: **A malloc() clone — `my_malloc()`**
- Implement a basic heap allocator using `sbrk()`
- Support `my_malloc()` and `my_free()`

Goal: This is where the memory layout model *clicks completely*.

---

**The progression logic:**
Each project is small enough to finish in a weekend session, but directly answers *"where does this concept actually live in real code?"* — which is exactly what textbook reading alone never gives you.

---

**Phase 2 Build Path — Networking (paired with Top-Down Approach)**

The theme here is: you already know the *layers* — now you're going to feel them from the *inside*, at the OS level.

---

**Week 1–2 | Reading: Application Layer (Ch.2)**
Build: **A tiny HTTP client in C**
- Open a raw TCP socket
- Manually send a valid HTTP GET request as a string
- Print the raw response you get back

Goal: Realize that your browser is ultimately just doing this — sending formatted text over a socket.

---

**Week 3–4 | Reading: Transport Layer (Ch.3)**
Build: **A TCP chat program**
- One server, one client
- They can send messages back and forth
- Use `socket()`, `bind()`, `listen()`, `accept()`, `connect()`

Goal: Understand that TCP's reliability isn't magic — it's the OS managing buffers and retransmission under the hood for you.

---

**Week 5–6 | Reading: Network Layer (Ch.4–5)**
Build: **A traceroute clone**
- Send packets with incrementing TTL values
- Print each hop's IP address as packets expire

Goal: Watch your packets actually travel through Layer 3 in real time. The routing concepts stop being abstract.

---

**Week 7–8 | Reading: Application Layer Security / TLS (Ch.8)**
Build: **Upgrade your HTTP client to HTTPS**
- Use OpenSSL library to wrap your existing socket
- Complete a TLS handshake manually
- Fetch https://google.com and print the response

Goal: Connect your earlier DNS → HTTP → HTTPS mental model to actual code. The RSA/TLS handshake you described earlier becomes concrete.

---

**The connection back to OS (the payoff):**

By the end of Phase 2, you'll naturally start asking questions like:
- *When does my `send()` call actually put data on the wire?*
- *Where does the incoming packet live before my program reads it?*

Those questions live at the **OS + Networking boundary** — and at that point you'll be reasoning like a systems engineer, not just a CS grad filling gaps.

---

**Full picture so far:**

| Phase | Theme | Capstone mental model |
|---|---|---|
| Phase 1 | OS | "I can see memory" |
| Phase 2 | Networking | "I can trace a packet to my code" |
| Phase 3 | Architecture | "I know why my code is slow or fast" |

---

**Phase 3 Build Path — Computer Architecture (paired with Patterson & Hennessy)**

The theme here is: you've seen memory from the OS side (Phase 1) and from the network side (Phase 2) — now you're going down **one more level** to understand why your code runs fast or slow at the hardware level.

> Note: Patterson & Hennessy is dense. Don't read it cover to cover — use it as a reference and follow the reading targets below.

---

**Week 1–2 | Reading: Instruction Set Architecture (Ch.2)**
Build: **A tiny assembly inspector**
- Write 3 versions of the same simple function in C (e.g. sum an array)
- Compile each with `gcc -S` to see the assembly output
- Compare the instruction count between versions

Goal: See that your C code is just a human-friendly way of writing CPU instructions. The compiler is translating for you.

---

**Week 3–4 | Reading: Memory Hierarchy & Cache (Ch.5)**
Build: **A cache behavior demonstrator**
- Write two versions of a matrix multiplication
  - Version 1: naive row × column order
  - Version 2: cache-friendly loop reordering
- Benchmark both with `time` or `perf`

Goal: See a real, measurable performance difference caused purely by cache behavior — not algorithm complexity.

---

**Week 5–6 | Reading: Pipelining (Ch.4)**
Build: **A branch prediction experiment**
- Create a large array, half 1s half 0s
- Version 1: unsorted array, sum only 1s
- Version 2: sorted array, same operation
- Benchmark both

Goal: Feel the cost of branch misprediction in real numbers. This is why sorting data before processing it is sometimes surprisingly faster.

---

**Week 7–8 | Reading: I/O & Interrupts (Ch.6)**
Build: **A DMA & interrupt behavior observer**
- Write a program that does heavy file I/O
- Use `strace` to observe every syscall your program makes
- Identify where your program *blocks* waiting for hardware

Goal: Connect the I/O chapter directly to what your OS is doing underneath — interrupts, device drivers, and why I/O is always the bottleneck.

---

**The full 3-phase payoff:**

By the end of all three phases, when you look at a piece of code you'll naturally think in layers:

```
Your Code
    ↓
How it maps to memory (Phase 1 — OS)
    ↓
How data moves across the network (Phase 2 — Networking)
    ↓
Why it runs fast or slow on hardware (Phase 3 — Architecture)
```

That layered thinking is exactly what separates a systems-aware engineer from an average one.

---

**Your complete blueprint:**

| Phase | Duration | Book | Capstone Project |
|---|---|---|---|
| 1 — OS | Month 1–2 | OSTEP | `my_malloc()` clone |
| 2 — Networking | Month 3–4 | Top-Down Approach | HTTPS client in C |
| 3 — Architecture | Month 5–6 | Patterson & Hennessy | Cache benchmark suite |
| Algorithms | Ongoing | CLRS (reference) | 2–3 Leetcode mediums/week |

---

One last practical note: **C is the common thread across all three phases.** If your C is rusty or weak, spend the first 1–2 weeks of Phase 1 just getting comfortable with pointers and manual memory management before diving into OSTEP. Everything else will be smoother for it.

---

Honest answer: **Phase 1 and 2 fill 80% of your practical gap.**

For most software engineering roles, Phase 1 + 2 gives you:
- Solid systems reasoning
- Ability to debug memory and performance issues
- Confidence in backend and infrastructure discussions
- Strong foundation for security concepts

---

**Phase 3 becomes important only if you're heading toward:**
- Embedded systems or firmware
- High-frequency trading / ultra-low latency systems
- Game engine or graphics programming
- Compiler or runtime development
- CPU/hardware-adjacent roles

---

**My suggestion for your situation:**

Do Phase 1 and 2 fully and seriously. After that, ask yourself:
- *Do I still feel a gap?*
- *Is my work or target role touching hardware-level performance?*

If yes → do Phase 3. If no → replace Phase 3 with going **deeper on OS + Networking** through a bigger project like xv6, which naturally pulls in just enough architecture without requiring you to read Patterson & Hennessy cover to cover.

---

**Bottom line:** Phase 3 is a *specialization*, not a *foundation*. Don't let it become a reason to delay starting Phase 1 today.

---
