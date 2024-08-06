#include <iostream>
#include <graphics.h>
#include <stdlib.h>  // for exit function


void drawTrain(int offset) {
    // Draw the first box
    setfillstyle(SOLID_FILL, 12);
    rectangle(40 + offset, 340, 120 + offset, 407);
    floodfill(41 + offset, 350, 15);

    setfillstyle(SOLID_FILL, 4);
    rectangle(30 + offset, 330, 130 + offset, 340);
    floodfill(31 + offset, 331, 15);

    setfillstyle(SOLID_FILL, 9);
    rectangle(50 + offset, 360, 70 + offset, 380);
    floodfill(51 + offset, 370, 15);

    setfillstyle(SOLID_FILL, 9);
    rectangle(90 + offset, 360, 110 + offset, 380);
    floodfill(91 + offset, 370, 15);

    setfillstyle(SOLID_FILL, 11);
    rectangle(120 + offset, 390, 150 + offset, 398);
    floodfill(121 + offset, 391, 15);

    setcolor(8);
    setfillstyle(SOLID_FILL, 8);
    circle(55 + offset, 410, 12);
    floodfill(56 + offset, 420, 8);

    setfillstyle(SOLID_FILL, 8);
    circle(99 + offset, 410, 12);
    floodfill(100 + offset, 420, 8);

    setcolor(15);

    // Draw the second box
    setfillstyle(SOLID_FILL, 7);
    rectangle(150 + offset, 340, 230 + offset, 407);
    floodfill(151 + offset, 341, 15);

    setfillstyle(SOLID_FILL, 4);
    rectangle(140 + offset, 330, 240 + offset, 340);
    floodfill(141 + offset, 331, 15);

    setfillstyle(SOLID_FILL, 9);
    rectangle(160 + offset, 360, 180 + offset, 380);
    floodfill(161 + offset, 361, 15);

    setfillstyle(SOLID_FILL, 9);
    rectangle(200 + offset, 360, 220 + offset, 380);
    floodfill(201 + offset, 361, 15);

    setcolor(8);
    setfillstyle(SOLID_FILL, 8);
    circle(165 + offset, 410, 12);
    floodfill(166 + offset, 411, 8);

    setfillstyle(SOLID_FILL, 8);
    circle(210 + offset, 410, 12);
    floodfill(211 + offset, 411, 8);

    setcolor(15);

    // Draw the engine
    setfillstyle(SOLID_FILL, 10);
    rectangle(260 + offset, 340, 310 + offset, 407);
    floodfill(261 + offset, 341, 15);

    setfillstyle(SOLID_FILL, 4);
    rectangle(250 + offset, 330, 320 + offset, 340);
    floodfill(251 + offset, 331, 15);

    setcolor(8);
    setfillstyle(SOLID_FILL, 8);
    circle(284 + offset, 406, 18);
    floodfill(285 + offset, 416, 8);

    setcolor(15);

    setfillstyle(SOLID_FILL, 3);
    rectangle(310 + offset, 370, 380 + offset, 407);
    floodfill(311 + offset, 380, 15);

    setfillstyle(SOLID_FILL, 5);
    rectangle(270 + offset, 350, 290 + offset, 370);
    floodfill(271 + offset, 360, 15);

    setcolor(8);
    setfillstyle(SOLID_FILL, 8);
    circle(328 + offset, 410, 12);
    floodfill(329 + offset, 420, 8);

    setfillstyle(SOLID_FILL, 8);
    circle(364 + offset, 410, 12);
    floodfill(365 + offset, 420, 8);

    setcolor(15);

    // Draw the fire
    setfillstyle(SOLID_FILL, 1);
    rectangle(350 + offset, 330, 365 + offset, 370);
    floodfill(351 + offset, 340, 15);

    setfillstyle(SOLID_FILL, 4);
    rectangle(347 + offset, 325, 367 + offset, 330);
    floodfill(348 + offset, 326, 15);

    setfillstyle(SOLID_FILL, 1);
    rectangle(230 + offset, 390, 260 + offset, 398);
    floodfill(231 + offset, 391, 15);

    setcolor(15);

    // Draw the light
    setfillstyle(SOLID_FILL, 14);
    rectangle(380 + offset, 380, 386 + offset, 395);
    floodfill(381 + offset, 381, 15);

    // Draw the smoke
    setfillstyle(SOLID_FILL, 15);
    circle(350 + offset, 310, 5);
    floodfill(351 + offset, 311, 15);

    setfillstyle(SOLID_FILL, 15);
    circle(355 + offset, 319, 3);
    floodfill(356 + offset, 320, 15);

    setfillstyle(SOLID_FILL, 15);
    circle(365 + offset, 310, 4);
    floodfill(366 + offset, 311, 15);

    setfillstyle(SOLID_FILL, 15);
    circle(354 + offset, 300, 3);
    floodfill(355 + offset, 301, 15);

    setfillstyle(SOLID_FILL, 15);
    circle(350 + offset, 290, 5);
    floodfill(351 + offset, 291, 15);

    setfillstyle(SOLID_FILL, 15);
    circle(344 + offset, 300, 3);
    floodfill(345 + offset, 301, 15);
}
int knapsack(int W, int wt[], int val[], int n) {
    int K[n + 1][W + 1];

    // Build table K[][] in bottom up manner
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = std::max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    return K[n][W];
}
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    // Example usage of the knapsack algorithm
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    std::cout << "Maximum value: " << knapsack(W, wt, val, n) << std::endl;


    for (int i = 0; i < 640; i++)
    {
        cleardevice();

        // Draw the background
        outtextxy(450, 60, ".");
        outtextxy(480, 50, "'");
        outtextxy(410, 199, "'");
        outtextxy(450, 290, "'");
        outtextxy(440, 190, ".");
        outtextxy(400, 260, "'");
        outtextxy(580, 250, "'");
        outtextxy(410, 199, "'");
        outtextxy(550, 340, ".");
        outtextxy(640, 190, "'");
        outtextxy(200, 40, "'");
        outtextxy(230, 10, ".");
        outtextxy(550, 99, "'");
        outtextxy(100, 50, "'");
        outtextxy(400, 100, ".");
        outtextxy(150, 60, ".");
        outtextxy(280, 50, "'");
        outtextxy(310, 199, "'");
        outtextxy(50, 290, "'");
        outtextxy(120, 190, "'");
        outtextxy(100, 260, "'");
        outtextxy(280, 250, "'");
        outtextxy(30, 199, "'");
        outtextxy(250, 240, "'");
        outtextxy(340, 190, ".");

        // Draw the moon
        setfillstyle(SOLID_FILL, 15);
        circle(295, 60, 40);
        floodfill(296, 70, 15);

        // Draw the text
        settextstyle(3, 0, 2);
        outtextxy(200, 448, "CREATED BY ALLAMPRABHU 3PD22CS011 ");

        // Draw the line
        line(0, 424, 700, 424);

        // Draw the first train
        drawTrain(i);

        // Draw the second train
        drawTrain(i - 500); // Adjust offset to place second train in a different position

        delay(25);
    }

    closegraph();
    return 0;
}

