# BWS-V2
BWS-V2 is a emulation of a reworked formula of the main BWS expression that is widely used in osu! by taking in account the "age" of a badge and give it a floating number ```weight```.

Made in C++ with standard libraries.

# to run
on the `src` folder:
```bash
g++ main.cpp Date.cpp -o BWS_parser
```
# Parsing file format

## THE FILE HAS TO BE CALLED `player_data.txt` OTHERWISE IT WON'T WORK
example:
```
player1; ActualRank; NoBadges; dd1-mm1-yyyy1; dd2-mm2-yyyy2; ...; dd(n)-mm(n)-yyyy(n)
player2; ActualRank; NoBadges; dd1-mm1-yyyy1; dd2-mm2-yyyy2; ...; dd(n)-mm(n)-yyyy(n)
player3; ActualRank; NoBadges; dd1-mm1-yyyy1; dd2-mm2-yyyy2; ...; dd(n)-mm(n)-yyyy(n)
player4; ActualRank; NoBadges; dd1-mm1-yyyy1; dd2-mm2-yyyy2; ...; dd(n)-mm(n)-yyyy(n)
...........................................................................................
playerN; ActualRank; NoBadges; dd1-mm1-yyyy1; dd2-mm2-yyyy2; ...; dd(n-1)-mm(n-1)-yyyy(n-1)
```

# Contribution
I'm open to make a better version of this formula, please contact me on Twitter (@akahitooo) or osu (Akahito), or DM me on discord (akahito.)

# How to Contribute

1. Fork the repository on GitHub.
2. Clone your forked repository to your local machine.
3. Create a new branch for your feature or bug fix.
4. Make your changes and commit them with clear and descriptive commit messages.
5. Push your changes to your forked repository.
6. Create a pull request to the main repository, describing your changes in detail.

# Running Tests

To run the unit tests, use the following command in the `tests` folder:
```bash
g++ -o runTests DateTests.cpp DateUtilsTests.cpp MathUtilsTests.cpp ParserTests.cpp PlayerTests.cpp -I ../include
./runTests
```

# License

This project is licensed under the MIT License - see the LICENSE file for details.
