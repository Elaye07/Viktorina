//========================================================================
//! @file       Main.cpp
//{=======================================================================
//!
//! @brief      <Заголовок>\n
//! @brief      <Подзаголовок>
//!
//! @version    [Version 0.01 alpha, build 1]
//! @author     Copyright (C) <Автор>, <Год> (<Имя> <Почта>)
//! @date       <Дата>
//!
//! @par        Протестировано
//!           - (TODO: список платформ)
//!
//! @todo     - (TODO: список ближайших планов по этому файлу)
//!
//! @bug      - (TODO: список найденных ошибок в этом файле)
//!
//! @par        История изменений файла
//!           - Версия 0.01 Alpha
//!             - Только что созданный файл
//!
//}=======================================================================

#include "TXLib.h"
#include <fstream>

using namespace std;

struct Forma
{
    string text_q;
    HDC picture_a1;
    string text_a1;
    HDC picture_a2;
    string text_a2;
    HDC picture_a3;
    string text_a3;
    int n_right_a;

    void draw()
    {
    txDrawText (200, 90, 780, 160,  text_q.c_str());                      // question
     txBitBlt(txDC(), 20, 203, 260, 275,  picture_a1);                      // picture 1
    txDrawText (20, 520, 280, 610,  text_a1.c_str());                     // answer 1
     txBitBlt(txDC(), 352, 203, 285, 275, picture_a2);                      // picture 2
    txDrawText (335, 520, 660, 610, text_a2.c_str());                     // answer 2
     txBitBlt(txDC(), 713, 203, 275, 275, picture_a3);                      // picture 3
    txDrawText (720, 520, 990, 610, text_a3.c_str());                     // answer 3
    }
};



void Maket()
{

    txSetColor (TX_WHITE);
    txSetFillColor (TX_TRANSPARENT);
    txRectangle (20, 610, 280, 520);    //buttom 1 (answer)
    txRectangle (345, 610, 640, 520);   //buttom 2 (answer)
    txRectangle (710, 610, 990, 520);   //buttom 3 (answer)
    txRectangle (200, 160, 780, 90);    //question
    txRectangle (18, 480, 282, 200);    //picture 1
    txRectangle (350, 480, 635, 200);   // picture 2
    txRectangle (710, 480, 990, 200);   // picture 3
    txRectangle (730, 80, 980, 20);     //question number

}


string getPart(string str, int *pos2)
{
    int pos1 = *pos2 + 1;
    *pos2 = str.find(",", pos1);
    string part = str.substr(pos1, *pos2-(pos1));
    return part;


}





int main()
    {
txCreateWindow (1000, 700);
txTextCursor (false);
//HDC fonch = txLoadImage("Pictures/ПОЛЕ.bmp");
//txBitBlt(txDC(), 0,0,1000,700, fonch);

Forma form_list[20];
int i = 0;
 setlocale(LC_ALL, "Russian");


    string str;

    ifstream file("test.txt");

    while(file.good())
    {
        getline(file, str);

        int pos2 = -1;
        form_list[i].text_q = getPart(str, &pos2);
        form_list[i].picture_a1 = txLoadImage(getPart(str, &pos2).c_str());
        form_list[i].text_a1 = getPart(str, &pos2);
        form_list[i].picture_a2 = txLoadImage(getPart(str, &pos2).c_str());
        form_list[i].text_a2 = getPart(str, &pos2);
        form_list[i].picture_a3 = txLoadImage(getPart(str, &pos2).c_str());
        form_list[i].text_a3 = getPart(str, &pos2);
        form_list[i].n_right_a = atoi(getPart(str, &pos2).c_str());
        i++;
    }
    file.close();




Forma form;


    HDC ulyan = txLoadImage("Pictures/Ульян.bmp");
    HDC mockv = txLoadImage("Pictures/Москва.bmp");
    HDC piter = txLoadImage("Pictures/ПИТЕР.bmp");

    int count_question = 11;
    int n_question = 1;
    char stu[20];
    int score = 0;



        while (n_question <= count_question)
    {
    txSetFillColor (TX_BLACK);
    txClear();
    txBegin();
    Maket();



    txSetColor (TX_LIGHTGREEN);
    txSelectFont ("Times", 40);
    txSetTextAlign (TA_CENTER);
    sprintf(stu, "Вопрос №%d из %d" , n_question, count_question);
    txTextOut(865, 30, stu);                         // Number question


    form = form_list[n_question-1];
    form.draw();




    //click answer 1 (left)
    if(txMouseButtons() == 1 &&
    txMouseX()>20 && txMouseX()<280 &&
    txMouseY()>520 && txMouseY() < 610 )
    {
        if (form.n_right_a == 1) score ++;
        while (txMouseButtons() == 1) txSleep(250);
        n_question ++;
    }



    //click answer 2 (middle)
    if(txMouseButtons() == 1 &&
    txMouseX()>352 && txMouseX()<660 &&
    txMouseY()>520 && txMouseY() < 610 )
    {
        if (form.n_right_a == 2) score ++;
        while (txMouseButtons() == 1) txSleep(250);
        n_question ++;
    }



     //click answer 3 (right)
    if(txMouseButtons() == 1 &&
    txMouseX()>720 && txMouseX()<990 &&
    txMouseY()>520 && txMouseY() < 610 )
    {
        if (form.n_right_a == 3) score ++;
        while (txMouseButtons() == 1) txSleep(250);
        n_question ++;
    }

    txEnd();
    txSleep(20);
    }

    txSetFillColor (TX_BLACK);
    txClear();
    sprintf(stu, "Ваш результат %d из %d" , score , count_question);
    txTextOut(500, 350, stu);                         // test result






    return 0;
    }

