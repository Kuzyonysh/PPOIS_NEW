
#include "D:\Projects\TagGame\Tag\Tag.h"
#include "D:\Projects\TagGame\Tag\UI.h"
#include <gtest/gtest.h>



TEST(GameTest, ConstructorInitializesField) {
    Game g;
    int zeros = 0;
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            if (g[i][j] == 0) zeros++;
    EXPECT_EQ(zeros, 1); 
}

TEST(GameTest, FillSetsCorrectField) {
    Game g;
    g.fill();
    int expected = 1;
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j) {
            if (i == 3 && j == 3)
                EXPECT_EQ(g[i][j], 0);
            else
                EXPECT_EQ(g[i][j], expected++);
        }
}

TEST(GameTest, ChangeCreatesSolvableBoardAndPreservesNumbers) {
    Game g;
    g.fill();
    g.change();

    bool seen[16] = { false };
    int arr[16];
    int k = 0;
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            arr[k++] = g[i][j];

    for (int i = 0; i < 16; i++) {
        ASSERT_GE(arr[i], 0);
        ASSERT_LE(arr[i], 15);
        seen[arr[i]] = true;
    }
    for (int i = 0; i < 16; i++)
        EXPECT_TRUE(seen[i]);

    EXPECT_TRUE(g.isSolvable(arr));
}

TEST(GameTest, IsSolvableCorrectness) {
    Game g;
    int solvable[16] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,0 };
    int unsolvable[16] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,15,14,0 };
    EXPECT_TRUE(g.isSolvable(solvable));
    EXPECT_FALSE(g.isSolvable(unsolvable));
}

TEST(GameTest, MoveWorksCorrectly) {
    Game g;
    g.fill();
    EXPECT_EQ(g.GetEmptyRow(), 3);
    EXPECT_EQ(g.GetEmptyCol(), 3);

    EXPECT_FALSE(g.move('D'));
    EXPECT_FALSE(g.move('S'));

    EXPECT_TRUE(g.move('A'));
    EXPECT_EQ(g.GetEmptyCol(), 2);

    EXPECT_TRUE(g.move('W'));
    EXPECT_EQ(g.GetEmptyRow(), 2);

    EXPECT_TRUE(g.move('a'));
    EXPECT_TRUE(g.move('w'));
}

TEST(GameTest, IsRightDetectsWinningBoard) {
    Game g;
    g.fill();
    EXPECT_TRUE(g.isRight());

    g.change(); // likely non-winning
}

TEST(GameTest, OperatorIndexAccess) {
    Game g;
    g.fill();
    EXPECT_EQ(g[0][0], 1);
    EXPECT_EQ(g[3][3], 0);

    g[0][0] = 42;
    EXPECT_EQ(g[0][0], 42);
}

TEST(GameTest, StreamOutput) {
    Game g;
    g.fill();
    std::ostringstream out;
    out << g;
    std::string s = out.str();
    EXPECT_NE(s.find("1"), std::string::npos);
    EXPECT_NE(s.find("."), std::string::npos);
}

// --- UI tests (переведены на английский) ---
TEST(UITest, ExitCommand) {
    Game g;
    UI ui(g);
    std::istringstream input("E\n");
    std::ostringstream output;

    auto cin_buf = std::cin.rdbuf(input.rdbuf());
    auto cout_buf = std::cout.rdbuf(output.rdbuf());

    ui.start();

    std::cin.rdbuf(cin_buf);
    std::cout.rdbuf(cout_buf);

    std::string out = output.str();
    EXPECT_NE(out.find("You exited the game."), std::string::npos);
}

TEST(UITest, CheckCellValue) {
    Game g;
    UI ui(g);
    std::istringstream input("C\n0\n0\nE\n");
    std::ostringstream output;

    auto cin_buf = std::cin.rdbuf(input.rdbuf());
    auto cout_buf = std::cout.rdbuf(output.rdbuf());

    ui.start();

    std::cin.rdbuf(cin_buf);
    std::cout.rdbuf(cout_buf);

    std::string out = output.str();
    EXPECT_NE(out.find("Cell value [0][0]"), std::string::npos);
}

TEST(UITest, InvalidCoordinates) {
    Game g;
    UI ui(g);
    std::istringstream input("C\n5\n5\nE\n");
    std::ostringstream output;

    auto cin_buf = std::cin.rdbuf(input.rdbuf());
    auto cout_buf = std::cout.rdbuf(output.rdbuf());

    ui.start();

    std::cin.rdbuf(cin_buf);
    std::cout.rdbuf(cout_buf);

    std::string out = output.str();
    EXPECT_NE(out.find("Error: invalid coordinates!"), std::string::npos);
}

TEST(UITest, InvalidCommand) {
    Game g;
    UI ui(g);
    std::istringstream input("X\nE\n");
    std::ostringstream output;

    auto cin_buf = std::cin.rdbuf(input.rdbuf());
    auto cout_buf = std::cout.rdbuf(output.rdbuf());

    ui.start();

    std::cin.rdbuf(cin_buf);
    std::cout.rdbuf(cout_buf);

    std::string out = output.str();
    EXPECT_NE(out.find("Invalid command!"), std::string::npos);
}

TEST(UITest, MoveAndWin) {
    Game g;
    g.fill();
    UI ui(g);
    std::istringstream input("A\nE\n");
    std::ostringstream output;

    auto cin_buf = std::cin.rdbuf(input.rdbuf());
    auto cout_buf = std::cout.rdbuf(output.rdbuf());

    ui.start();

    std::cin.rdbuf(cin_buf);
    std::cout.rdbuf(cout_buf);

    std::string out = output.str();
    EXPECT_NE(out.find("Commands:"), std::string::npos);
}

TEST(UITest, InvalidMove) {
    Game g;
    UI ui(g);
    g.fill();

    std::istringstream input("S\nD\nE\n");
    std::ostringstream output;

    auto cin_buf = std::cin.rdbuf(input.rdbuf());
    auto cout_buf = std::cout.rdbuf(output.rdbuf());

    ui.start();

    std::cin.rdbuf(cin_buf);
    std::cout.rdbuf(cout_buf);

    std::string out = output.str();
    EXPECT_NE(out.find("Move not possible!"), std::string::npos);
}

TEST(UITest, GameWinScenario) {
    Game g;
    UI ui(g);

    g.fill();
    std::istringstream input("E\n");
    std::ostringstream output;

    auto cin_buf = std::cin.rdbuf(input.rdbuf());
    auto cout_buf = std::cout.rdbuf(output.rdbuf());

    ui.start();

    std::cin.rdbuf(cin_buf);
    std::cout.rdbuf(cout_buf);

    std::string out = output.str();
    EXPECT_NE(out.find("You exited the game."), std::string::npos);
}

TEST(UITest, BasicCommandsScenario) {
    Game g;
    UI ui(g);

    g.fill(); 
    istringstream input("C\n0\n0\nX\nW\nE\n");
    ostringstream output;

    auto cin_buf = cin.rdbuf(input.rdbuf());
    auto cout_buf = cout.rdbuf(output.rdbuf());

    ui.start();

    cin.rdbuf(cin_buf);
    cout.rdbuf(cout_buf);

    string out = output.str();
    EXPECT_NE(out.find("Cell value [0][0]"), string::npos); // проверка клетки
    EXPECT_NE(out.find("Invalid command!"), string::npos);  // неверна€ команда
    EXPECT_NE(out.find("You exited the game."), string::npos); // выход
}
// “ест провер€ет движение влево и вверх с невозможными ходами
TEST(UITest, MoveAllDirections) {
    Game g;
    UI ui(g);

    g.fill(); // пуста€ клетка в правом нижнем углу

    // ѕопробуем движение вниз и вправо (невозможно), потом влево и вверх (возможно)
    istringstream input("S\nD\nA\nW\nE\n");
    ostringstream output;

    auto cin_buf = cin.rdbuf(input.rdbuf());
    auto cout_buf = cout.rdbuf(output.rdbuf());

    ui.start();

    cin.rdbuf(cin_buf);
    cout.rdbuf(cout_buf);

    string out = output.str();
    EXPECT_NE(out.find("Move not possible!"), string::npos); // S и D
    EXPECT_NE(out.find("Commands:"), string::npos);          // цикл продолжаетс€
    EXPECT_NE(out.find("You exited the game."), string::npos);
}

// “ест провер€ет проверку значений на границах пол€
TEST(UITest, CheckEdgeCoordinates) {
    Game g;
    UI ui(g);
    g.fill();

    // ѕроверим все 4 угла
    istringstream input("C\n0\n0\nC\n0\n3\nC\n3\n0\nC\n3\n3\nE\n");
    ostringstream output;

    auto cin_buf = cin.rdbuf(input.rdbuf());
    auto cout_buf = cout.rdbuf(output.rdbuf());

    ui.start();

    cin.rdbuf(cin_buf);
    cout.rdbuf(cout_buf);

    string out = output.str();
    EXPECT_NE(out.find("Cell value [0][0]"), string::npos);
    EXPECT_NE(out.find("Cell value [0][3]"), string::npos);
    EXPECT_NE(out.find("Cell value [3][0]"), string::npos);
    EXPECT_NE(out.find("Cell value [3][3]"), string::npos);
    EXPECT_NE(out.find("You exited the game."), string::npos);
}
TEST(UITest, CheckCellInvalidInputHandled) {
    Game g;
    UI ui(g);
    g.fill();

    // ¬вод команды C, а затем слишком большие координаты
    istringstream input("C\n10\n10\nE\n");
    ostringstream output;

    auto cin_buf = cin.rdbuf(input.rdbuf());
    auto cout_buf = cout.rdbuf(output.rdbuf());

    ui.start();

    cin.rdbuf(cin_buf);
    cout.rdbuf(cout_buf);

    string out = output.str();
    // ѕровер€ем, что UI обработал некорректные координаты
    EXPECT_NE(out.find("Error: invalid coordinates!"), string::npos);
    // ѕровер€ем, что UI корректно завершилс€
    EXPECT_NE(out.find("You exited the game."), string::npos);
}
