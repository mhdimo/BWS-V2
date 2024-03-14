# BWS-V2
BWS-V2 is a emulation of a reworked formula of the main BWS formula widely used in osu! by taking in account the "age" of a badge.

Made in C++ without any specific crazy library

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
