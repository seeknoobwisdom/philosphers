# 🧠 Philosophers

**Philosophers** is a multithreaded simulation of the classic *Dining Philosophers Problem*, implemented in C using **POSIX threads** and **mutexes**.  
This project is part of the **42 curriculum** and focuses on concurrency, thread safety, synchronization, and avoiding deadlocks and starvation.

![Language](https://img.shields.io/badge/C-100%25-blue)
![Threads](https://img.shields.io/badge/pthreads-POSIX-yellow)
![Status](https://img.shields.io/badge/Project-Done-success)

---

## 📖 Table of Contents // to be addit later

- [About](#about)
- [Rules](#rules)
- [Installation](#installation)
- [Usage](#usage)
- [Program Flow](#program-flow)
- [Thread Safety](#thread-safety)
- [Project Structure](#project-structure)
- [License](#license)

---

## 🧩 About

The **Dining Philosophers Problem** illustrates synchronization issues and the need to prevent *deadlock* and *race conditions*. Each philosopher alternates between:

- **Thinking 🤔**
- **Eating 🍝**
- **Sleeping 😴**

Philosophers need **two forks** to eat, shared between neighbors. Correct handling of these shared resources is the core of the challenge.

---

## 📜 Rules

- If a philosopher doesn’t start eating within `time_to_die` ms, they die.
- Eating takes `time_to_eat` ms.
- Sleeping takes `time_to_sleep` ms.
- Optional: if all philosophers eat at least `number_of_times_each_philosopher_must_eat`, the simulation ends.
- Only **one philosopher can use a fork at a time**.
- Forks are represented by **mutexes**.
- Actions must be printed in real time with timestamps.

---

## 🛠 Installation

```bash
git clone https://github.com/yourusername/philosophers.git
cd philosophers
make

usage ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
