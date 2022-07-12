# TIC-TAC-TOE GAME :video_game:
**TIC-TAC-TOE** is a personal project with **2 game modes** (One and Two Players), the program have made for **cmd** using **two functions**, the main and board.<p/>

## 🚀 Technologies Used
<div>
  <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/c/c-original.svg" width="60" height="60"/>
</div>

## :hammer: Functionalities
<p>✔ Tic-tac-toe with 1 player versus bot mode</p>
<p>✔ Play with friend in 2 player mode </p>
<p>✔ Show score(acumulative) in the end </p>

## :clapper: How it works
**Main Function:** This function is responsible for receive mode of game(If the main fuction does not validate the game mode, be in a loop), one or two player, passing as parametrer the number of players and score for the board function in next.</br>
**Board Function:** Is responsible for generate the board whit one integer matrix, the ASCII table and centralizing decisions making. It transform the integers number in char on output and altering the memory address of the scoring vector.</br>
**Mode games:**
- **One player:** In this mode, have a bot as enemy in medium difficulty. The bot's logic is to read the entire matrix, if it has a chance to win, it will execute this action as a priority, if not, it will analyze if there is a way for the player to win in the matrix, if so, it will block the player's victory, if not, he will play on the board randomly, leaving the game in a possible way to win. Its verification is done in the following order: It verifies the matrix horizontally, after that verifies it vertically and finally verifies the possibilities of the cross. Its checks are largely done with loops of loops with indices to check the status of the position, showing the user the matrix already changed and formatted.
- **Two players:** In two player mode, player one identified as X and player two identified as O alternate moves to get a sequence of their respective symbols aligned. The program separates the two players in the rest of the division of the rounds variable by 2, differentiating each player by an odd or even number, in this game mode the table is shown in each move instead of being shown only in odd moves, using the verification matrix to identify a winner, if the maximum number of rounds is reached and there is no winner, there will be a tie, if so, the program starts a score count.</br>
<div align="center">
  <img src="" height="365">
</div><br>
<a href="https://instagram.com/marcosd_marques" target="_blank"><img src="https://raw.githubusercontent.com/Aakarsh-B/trying-repos/master/insta.svg" width="40" height="40" target="_blank"></a>
<a href = "mailto:mdmarques70@gmail.com"><img src="https://www.freeiconspng.com/thumbs/gmail-icon/gmail-logo-icon-2.png" width="40" height="40" target="_blank"></a>
</div></a>

