
---

## 🌐 GitHub `README.md` (Public Display)

```markdown
# 🧠 Philosophers

Simulates the classic **Dining Philosophers Problem** using POSIX threads and mutexes, following the strict rules of 42 school.

![Language](https://img.shields.io/badge/C-100%25-blue)
![Threads](https://img.shields.io/badge/pthreads-POSIX-yellow)
![Status](https://img.shields.io/badge/Project-Done-success)

---

## 📖 Description

The goal is to simulate philosophers who:
- Think 🤔
- Eat 🍝
- Sleep 😴  
…without causing deadlocks or starving anyone.

All resource sharing is thread-safe using `pthread_mutex_t`.

---

## 🏗️ Compilation

```bash
make
