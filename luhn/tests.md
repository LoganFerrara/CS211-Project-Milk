# Luhn Validation – Test Documentation

## Test Cases

| Test # | Test Input | Expected Result | Actual Result |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| 1 | `4532015112830366` | Correct format; checksum passes | Pass |
| 2 | `4532015112830367` | Correct format; checksum fails | Pass |
| 3 | `0000000000000018` | Leading zeros preserved; checksum passes | Pass |
| 4 | `453201511283036` | Reject: 15 digits | Fail |
| 5 | `45320151128303666` | Reject: 17 digits | Fail |
| 6 | `453201511283036X` | Reject: non-digit character | Fail |
| 7 | `1234 5678 9012 3456` | Reject: internal spaces | Fail |
| 9 | Several valid and invalid checks followed by `n` | Results correct; program exits cleanly | Pass |

## Testing Notes

- Tested valid and invalid Luhn checksums.
- Tested multiple card number attempts without restarting.
- Tested the exit option.
- Additional malformed input and leading-zero tests still need to be verified.
