# Source entry points

Runnable new implementation: `reconstruction/model.py`; checks: `reconstruction/test_model.py`. Hardware implementation: `reconstruction/firmware/firmware.ino`. Read `CIRCUIT.md` before use.

## Earlier design notes

# Code and implementation record

## Original source status

Historical portfolio description only; original source, measurements and photographs not supplied.

No original code recovered for this project. Exact pin maps, libraries, timings and circuit values are intentionally not invented.

## Reconstructed pseudocode

This is newly written explanatory pseudocode, not executable firmware and not historical evidence.

```text
if sensor fault: indicate fault
else process baseline-relative reading
enter alert after persistent threshold crossing
clear only after recovery criteria
```

## What is needed before implementation

Confirm actual hardware/software interfaces, units, validation rules and failure states. Follow the separate methodology and its test plan. Not a certified smoke alarm; do not intentionally generate hazardous smoke or gas for demonstrations.
