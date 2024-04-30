---
title: "Sorting, only, like, super"
document: PwhatevsR0
date: 2019-08-23
audience:
  - EWG-I
author:
  - name: Zach Laine
    email: <whatwasthataddress@gmail.com>
toc: false
monofont: "DejaVu Sans Mono"

---

# Revisions

  - R0
    - Initial revision.

# Motivation

I want to sort faster -- super even.  For example:

::: tonytable

### Before
```c++
std::vector<int> ints = {0, 2, 1};
std::sort(ints.begin(), ints.end());
```

### After
```c++
std::vector<int> ints = {0, 2, 1};
std::super_sort(ints.begin(), ints.end(), true);
```

:::

# Design

```c++
template<typename I>
void super_sort(I first, I last, bool do_it_super);
```
