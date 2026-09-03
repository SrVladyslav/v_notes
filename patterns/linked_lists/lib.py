from __future__ import annotations

from typing import TypeVar

T = TypeVar("T")


class Node:
    def __init__(self, data: T, next: Node) -> None:
        self.data = data
        self.next = next
