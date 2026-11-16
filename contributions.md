# Project Contributions

## Group Members & Responsibilities
* **Cole (`@colex511`)**: 
  * Implemented the core Part A (2048) game logic, directional movement/merging functions, game loop, and board management (`PR #8`).
  * Implemented the `print_board` display function (`PR #3`).
  * Implemented the 2048 `save` and `load` file I/O functionality and `savegame.txt` validation (`PR #6`).
  * Reviewed and merged the finalized Luhn validation code (`PR #5`).
  * Created and compiled `contributions.md`.
* **Logan (`@LoganFerrara`)**: 
  * Created and configured the shared GitHub repository, initial folders, and group plan (`PR #1`).
  * Implemented and updated the finalized `main.cpp` and Part B Luhn checksum validation logic (`PR #5`).
  * Reviewed and merged teammate pull requests (`PR #3`, `PR #4`, `PR #6`, `PR #7`).
  * Created and executed the test suites and documented test evidence in `tests.md`.
* **Braeden (`@braedcrbs`)**: 
  * Created commented/explained Luhn code and Luhn validation documentation (`PR #2`, `PR #4`).
  * Documented function descriptions and program control flow for the 2048 game and save/load functions (`PR #7`, `PR #9`).
  * Reviewed and merged the 2048 game logic update (`PR #8`).
  * Created the preliminary `report.pdf` (including design explanations, dry runs, and workflow diagrams).

---

## Pull Request (PR) Log

| PR Link / Title | Author | Reviewer(s) | Merger | Checks Performed |
| :--- | :--- | :--- | :--- | :--- |
| [PR #1: Set up folders and group plan](https://github.com/LoganFerrara/CS211-Project-Milk/pull/1) | `@LoganFerrara` | `@braedcrbs`, `@colex511` | `@LoganFerrara` | Verified repository folder structure, initial plan, and collaborator access |
| [PR #2: Createed luhn_explained.cpp](https://github.com/LoganFerrara/CS211-Project-Milk/pull/2) | `@braedcrbs` | `N/A` (self-merged; reviewed in PR #4) | `@braedcrbs` | Checked inline comments, step-by-step Luhn algorithm explanations, and syntax |
| [PR #3: Add print_board function for 2048 game](https://github.com/LoganFerrara/CS211-Project-Milk/pull/3) | `@colex511` | `@LoganFerrara` | `@LoganFerrara` | Verified 5×5 grid alignment, empty-cell display, and clean compilation |
| [PR #4: luhn vali doc](https://github.com/LoganFerrara/CS211-Project-Milk/pull/4) | `@braedcrbs` | `@LoganFerrara` | `@LoganFerrara` | Reviewed Luhn input validation flow and documentation accuracy against requirements |
| [PR #5: Updated finished main.cpp](https://github.com/LoganFerrara/CS211-Project-Milk/pull/5) | `@LoganFerrara` | `@colex511` | `@colex511` | Compiled with `g++ -std=c++17 -Wall -Wextra`; tested Luhn edge cases and menu/loop exit |
| [PR #6: Implement save and load game functions](https://github.com/LoganFerrara/CS211-Project-Milk/pull/6) | `@colex511` | `@LoganFerrara` | `@LoganFerrara` | Tested valid saves, missing files, and corrupted `savegame.txt` preservation |
| [PR #7: Add files via upload](https://github.com/LoganFerrara/CS211-Project-Milk/pull/7) | `@braedcrbs` | `@LoganFerrara` | `@LoganFerrara` | Verified uploaded project files, formatting, and repository organization |
| [PR #8: Add 2048 game logic and board management](https://github.com/LoganFerrara/CS211-Project-Milk/pull/8) | `@colex511` | `@braedcrbs` | `@braedcrbs` | Verified four-direction sliding, merge-once rule, score updates, and win/game-over checks |
| [PR #9: documentation for svae and 2048 game](https://github.com/LoganFerrara/CS211-Project-Milk/pull/9) | `@braedcrbs` | `N/A` | `@braedcrbs` | Verified documentation matches actual 2048 and save/load function behavior |

---

## Outside Sources & Tools Used
* **Development Environments:** Visual Studio Code (local editing/compiling) and OnlineGDB (`onlinegdb.com` for quick C++ compilation and testing).
* **AI Tools:** ChatGPT (used for brainstorming C++ debugging strategies, syntax clarification, and formatting project documentation).
* **Verification & Code Checks:** All AI-assisted suggestions and outside references were manually reviewed line-by-line by group members, adapted to fit the CS211 project constraints (standard C++17, no external libraries), compiled cleanly with `g++ -std=c++17 -Wall -Wextra`, and verified against every required test case in `tests.md`.

---

## Group Declaration
All group members have reviewed the integrated codebase, understand both the 2048 and Luhn programs, and remain jointly responsible for the final submission.
