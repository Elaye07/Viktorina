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

struct Forma
{
    string text_q;
    HDC picture_answer1;
    string text_a1;
    HDC picture_answer2;
    string text_a2;
    HDC picture_answer3;
    string text_a3;
    int n_right_a;

    void draw()
    {
    txDrawText (200, 90, 780, 160,  text_q.c_str());                      // question
     txBitBlt(txDC(), 20, 203, 260, 275,  picture_answer1);                      // picture 1
    txDrawText (20, 520, 280, 610,  text_a1.c_str());                     // answer 1
     txBitBlt(txDC(), 352, 203, 285, 275, picture_answer2);                      // picture 2
    txDrawText (335, 520, 660, 610, text_a2.c_str());                     // answer 2
     txBitBlt(txDC(), 713, 203, 275, 275, picture_answer3);                      // picture 3
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







int main()
    {
txCreateWindow (1000, 700);
txTextCursor (false);

Forma form_list[20];
    form_list[0] = {"Столица России?",
              txLoadImage("Pictures/Ульян.bmp"),
              "Ульяновск",
              txLoadImage("Pictures/Москва.bmp"),
              "Москва",
              txLoadImage("Pictures/ПИТЕР.bmp"),
              "Санкт-Питербург", 2};
    form_list[1] = {"Родной город В. Ленина?",
              txLoadImage("Pictures/ПИТЕР.bmp"),
              "Санкт-Питербург",
              txLoadImage("Pictures/Москва.bmp"),
              "Москва",
              txLoadImage("Pictures/Ульян.bmp"),
              "Ульяновск", 3};

    form_list[2] = {"Город в названии которого есть имя?",
              txLoadImage("Pictures/Ульян.bmp"),
              "Ульяновск",
              txLoadImage("Pictures/Москва.bmp"),
              "Москва",
              txLoadImage("Pictures/ПИТЕР.bmp"),
              "Санкт-Питербург", 3};

Forma form;


    HDC ulyan = txLoadImage("Pictures/Ульян.bmp");
    HDC mockv = txLoadImage("Pictures/Москва.bmp");
    HDC piter = txLoadImage("Pictures/ПИТЕР.bmp");

    int count_question = 3;
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

