# 🧠 Dining Philosophers

> A 42-school multithreading project simulating the classic synchronization problem with real-time constraints and elegant C code.

---

## 📌 Overview

The **Dining Philosophers Problem** is a classic example in computer science for demonstrating issues and solutions around **concurrency**, **mutexes**, **deadlocks**, and **resource starvation**.

This project requires implementing a simulation where multiple philosophers sit at a round table. Each must **think**, **eat**, and **sleep**—but to eat, they need **two forks**, one on each side. Forks are shared with neighbors, so synchronization is key to avoid deadlocks and ensure fairness.

---

## 🛠️ Features

✅ Multithreading with `pthread`  
✅ Deadlock and starvation prevention  
✅ Accurate time simulation  
✅ Optional eating count argument  
✅ Clean code architecture with modular files  
✅ Norm-compliant (42 coding standard)

---

## 🧩 Problem Rules

- **Philosophers** sit in a circle and each needs two forks to eat.
- **Forks** are shared between neighbors and represented as **mutexes**.
- Philosophers must:
  - **Think**
  - **Pick up forks (mutex lock)**
  - **Eat**
  - **Put down forks (mutex unlock)**
  - **Sleep**
- A philosopher **dies** if they don’t eat within `time_to_die`.
- Optional: simulation stops if each philosopher eats `N` times.


---

## 🔧 Compilation

Use the provided `Makefile`:

```bash
make            # Compile the program
make clean      # Remove object files
make fclean     # Remove all binaries and object files
make re         # Recompile everything
```

---

## 🚀 Usage

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

### Example:

```bash
./philo 5 800 200 200
```

### Parameters:

| Argument | Description |
|----------|-------------|
| `number_of_philosophers` | Number of philosopher threads |
| `time_to_die`            | Time in ms before a philosopher dies if they don't eat |
| `time_to_eat`            | Time in ms to eat |
| `time_to_sleep`          | Time in ms to sleep |
| `number_of_times_each_philosopher_must_eat` _(optional)_ | Ends simulation when each philosopher has eaten this many times |

---

## 💡 How It Works

Each philosopher is represented by a **thread**. Forks are represented by **mutexes**. The simulation ensures:

- Mutual exclusion when accessing forks (mutex lock/unlock)
- Accurate timestamp logging
- A monitor thread checks if any philosopher has died
- Efficient use of time functions (`gettimeofday` or `clock_gettime`)

---

## 🔄 Philosopher Routine

```c
while (simulation_is_running)
{
    think();
    take_forks();   // Lock left and right mutexes
    eat();
    put_forks();    // Unlock mutexes
    sleep();
}
```

🧠 ➡️ 🍴 ➡️ 🍝 ➡️ 😴 ➡️ 🧠

---

## 🔎 Example Output

```
0 ms      1 has taken a fork
1 ms      1 has taken a fork
2 ms      1 is eating
203 ms    1 is sleeping
403 ms    1 is thinking
...
```

---


## ⚠️ Edge Cases Handled

- Only one philosopher (he will die after `time_to_die`)
- Zero or negative argument values
- Philosopher eats the exact number of times and exits
- Accurate time control with `usleep` correction

---

## 🧑‍💻 Author

Made with 💙 by [Asmae TAHTOUH]  
---

## 📚 References

- [Dining Philosophers on Wikipedia](https://en.wikipedia.org/wiki/Dining_philosophers_problem)
- [POSIX Threads (pthreads)](https://man7.org/linux/man-pages/man7/pthreads.7.html)
