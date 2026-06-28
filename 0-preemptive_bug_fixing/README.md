# 0-preemptive_bug_fixing

## Objective
This task demonstrates how to use an AI assistant (Gemini) acting as a Senior C Developer to preemptively identify and fix bugs in C code, specifically focusing on logical linking errors and memory safety.

## Files in this Directory
* **initial_code.c**: Contains the original vulnerable C function with a logical traversal error and missing memory checks.
* **refactored_code.c**: Contains the AI-corrected function that implements a `NULL` check for `malloc` and fixes list traversal termination.

## AI Tool Used
* **Tool:** Gemini
* **Prompt Strategy:** Role-playing ("Senior C Developer") combined with a structured checklist (Correctness and Memory handling) to ensure a comprehensive code review.
