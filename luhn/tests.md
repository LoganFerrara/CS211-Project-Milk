# Luhn Validation – Test Documentation

## Test Cases

| Test # | Test Input | Expected Result | Actual Result |
|---|---|---|---|
| 1 | `4532015112830366` | Correct format; checksum passes | Pass |
| 2 | `4532015112830367` | Correct format; checksum fails | Pass |
| 3 | `0000000000000018` | Leading zeros preserved; checksum passes | Pass |
| 4 | `453201511283036` | Reject: 15 digits | Fail |
| 5 | `45320151128303666` | Reject: 17 digits | Fail |
| 6 | `453201511283036X` | Reject: non-digit character | Fail |
| 7 | `1234 5678 9012 3456` | Reject: internal spaces | Fail |
| 8 | Several valid and invalid checks followed by `n` | Results correct; program exits cleanly | Pass |

## Testing Notes

- Tested valid and invalid Luhn checksums.
- Tested preservation of leading zeros.
- Tested incorrect input lengths.
- Tested non-digit characters and internal spaces.
- Tested multiple card number attempts without restarting.
- Tested the exit option.
