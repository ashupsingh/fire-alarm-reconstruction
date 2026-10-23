# Fire alarm: methodology

Status: researched reconstruction / proposed evaluation, prepared 23 October 2026. Not a recovered lab notebook.

## Existing account

An MQ2-based smoke/gas detection prototype with buzzer and LED alerts when sensor readings indicate a possible hazard.

The account above comes from the existing portfolio and is not independent verification. Listed stack: Arduino, MQ2 Gas Sensor, Buzzer, LED. Exact components and versions still need confirmation.

## System architecture

MQ2 response -> conditioned measurement -> hazard indication -> buzzer/LED

## Proposed engineering workflow

1. Document gas-sensor module and heater supply.
2. Record clean-air baseline and sensor faults.
3. Use staged simulated-input tests for threshold and notification logic.
4. Distinguish broad gas response from specific fire detection.

## Evaluation plan, not results

Record: Alert latency with simulated inputs; drift; recovery; missing-sensor indication. Use explicit units, test conditions, a baseline where relevant, repeated observations and a timestamped log. Report failure cases alongside successes. No numerical result is available from this reconstruction.

## Limitations and claim boundaries

Not a certified smoke alarm; do not intentionally generate hazardous smoke or gas for demonstrations.

## Design questions for an interview

- Explain the input, decision and output paths in the architecture above.
- What concrete fault would invalidate the output, and how would you detect it?
- Which design decision did you personally make, and what evidence do you retain?
- Which part of this proposed workflow differs from what you actually built?

## Research basis

[Winsen MQ-2 manufacturer manual](https://www.winsen-sensor.com/d/files/manual/mq-2.pdf) — consulted 23 October 2026. This source supports the underlying engineering topic, not the historical implementation. Workflow and evaluation proposals above are original analysis for this project.
