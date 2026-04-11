# AI: C Pre-Processor Co-Pilot

## Scenario
Scenario A — Arithmetic macro (`MAX(a, b)`)

## Files
| File | Description |
|------|-------------|
| `flawed_macro.c` | Initial unsafe macro with operator precedence and side-effect bugs |
| `safe_max.h` | Refactored header with include guards, DEBUG_LOG, and SAFE_MAX |

## AI Tool Used
ChatGPT — used as a Senior C Developer safety inspector and conditional code generator.

## How to compile
# Debug mode
gcc -DDEBUG_MODE -o main main.c

# Release mode
gcc -o main main.c
