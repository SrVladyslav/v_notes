## Linked Lists: When to Cut at the Middle

> [!IMPORTANT]
> If both halves can reach the same physical node **and you are going to modify `next` pointers**, split the list first.
>
> ```cpp
> Node<T>* second_half = middle_point->next;
> middle_point->next = nullptr;
> ```
>
> If you only compare or read values, sharing the middle node is often fine.
>
> ```text
> Shared node + READ  -> usually safe
> Shared node + WRITE -> split first
> ```

When splitting a linked list around a middle node, the key question is:

> **Will both traversals only read nodes, or will they modify `next` pointers?**

---

### Quick rule

```text
Only reading both halves           -> cutting is often NOT required
Rewiring / merging / interleaving  -> cut the list first
```

If two pointers can reach the same physical node and you later modify `next`,
you can accidentally create cycles or corrupt the list.

---

### Case 1: No cut needed — read-only comparison

Example: palindrome check

```text
1 -> 2 -> 3 -> 2 -> 1
          ^
        middle
```

If the second half is reversed starting from the middle:

```text
left traversal:
1 -> 2 -> 3 -> null

right traversal:
1 -> 2 -> 3 -> null
```

Both traversals may share the middle node.

That is usually fine if you only do:

```cpp
ptr = ptr->next;
value = ptr->data;
```

You are only following existing links.

No new `next` pointers are created, so sharing the middle node does not create a cycle.

---

### Case 2: Cut required — rewiring the list

Example: interleaving

```text
1 -> 2 -> 3 -> 4 -> 5
          ^
        middle
```

You want:

```text
1 -> 5 -> 2 -> 4 -> 3
```

Before reversing the second half, split the list:

```cpp
Node<T>* second_half = middle_point->next;
middle_point->next = nullptr;
```

Now:

```text
first half:
1 -> 2 -> 3 -> null

second half:
4 -> 5 -> null
```

Then reverse the second half:

```text
5 -> 4 -> null
```

Now both chains are independent:

```text
1 -> 2 -> 3 -> null

5 -> 4 -> null
```

This is important because the merge changes `next` pointers.

Without the cut, both traversals could eventually reach the same node.

Then an assignment like:

```cpp
curr->next = ptr_2;
```

could become effectively:

```cpp
node->next = node;
```

creating a cycle.

---

### Why `middle->next = nullptr` matters

This line:

```cpp
middle_point->next = nullptr;
```

does not delete any node.

It only removes the link between the two halves.

Think of it as:

```text
before:
A -> B -> C -> D -> E

after:
A -> B -> C -> null

D -> E -> null
```

The nodes still exist in memory.

You are only changing the structure of the list.

---

### Mental model

Treat `next` pointers as arrows.

```text
Reading arrows:
usually safe even if paths meet

Rewriting arrows:
dangerous if paths share nodes
```

So remember:

```text
Shared middle + READ  -> usually OK

Shared middle + WRITE -> split first
```

---

### Typical pattern

```cpp
Node<T>* middle_point = middle(head);

Node<T>* second_half = middle_point->next;

middle_point->next = nullptr;

Node<T>* reversed_second = reverse_list(second_half);
```

Use this pattern when you are going to:

```text
merge
interleave
reorder
rewire
```

the two halves independently.
