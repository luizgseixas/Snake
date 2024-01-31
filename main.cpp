#include <iostream>
#include <ncurses.h>
using namespace std;
bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;
void Setup() {
  gameOver = false;
  dir = STOP;
  x = width / 2;
  y = height / 2;
  fruitX = rand() % width;
  fruitY = rand() % height;
  score = 0;
}
// void Draw() {
//   system("clear");
//   for (int i = 0; i < width + 2; i++)
//     cout << "#";
//   cout << endl;

//   for (int i = 0; i < height; i++) {
//     for (int j = 0; j < width; j++) {
//       if (j == 0)
//         cout << "#";
//       if (i == y && j == x)
//         cout << "O";
//       else if (i == fruitY && j == fruitX)
//         cout << "F";
//       else
//         cout << " ";

//       if (j == width - 1)
//         cout << "#";
//     }
//     cout << endl;
//   }

//   for (int i = 0; i < width + 2; i++)
//     cout << "#";
//   cout << endl;
// }
void Draw() {
    // Limpar a tela
    clear();

    // Exibir a borda
    for (int i = 0; i < width + 2; i++)
        mvprintw(0, i, "#");

    // Exibir o conteúdo do jogo
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0)
                mvprintw(i + 1, j, "#");
            
            if (i == y && j == x)
                mvprintw(i + 1, j + 1, "O");
            else if (i == fruitY && j == fruitX)
                mvprintw(i + 1, j + 1, "F");
            else
                mvprintw(i + 1, j + 1, " ");

            if (j == width - 1)
                mvprintw(i + 1, j + 2, "#");
        }
    }

    // Exibir a borda inferior
    for (int i = 0; i < width + 2; i++)
        mvprintw(height + 1, i, "#");
    napms(120);
    // Atualizar a tela
    refresh();
}
void Input() {
  int key = getch();
  if (key != ERR) {
    switch (key) {
      case 'a':
        dir = LEFT;
        break;
      case 'd':
        dir = RIGHT;
        break;
      case 'w':
        dir = UP;
        break;
      case 's':
        dir = DOWN;
        break;
      case 'x':
        gameOver = true;
        break;
    }
  }
}
void Logic() {
  switch (dir) {
    case LEFT:
      x--;
      break;
    case RIGHT:
      x++;
      break;
    case UP:
      y--;
      break;
    case DOWN:
      y++;
      break;
    default:
      break;
  }
  if (x > width || x < 0 || y > height || y < 0)
    gameOver = true;
}
int main() {
  // Configurando o leitor de teclas
  initscr();
  nodelay(stdscr, TRUE);

  Setup();
  while (!gameOver) {
    Draw();
    Input();
    Logic();
    //Sleep(10); sleep(10);
  }
  endwin();
  cout << "GAME OVER";
  cout << endl;
  return 0;
}