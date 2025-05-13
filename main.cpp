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


    HDC ulyan = txLoadImage("Pictures/Ульян.bmp");
    HDC mockv = txLoadImage("Pictures/Москва.bmp");
    HDC piter = txLoadImage("Pictures/ПИТЕР.bmp");

    int count_question = 1;
    int n_question = 1;

    while (n_question <= count_question)
    {
    txBegin();
    Maket();



    txSetColor (TX_LIGHTGREEN);
    txSelectFont ("Times", 40);
    txSetTextAlign (TA_CENTER);

    txDrawText (730, 20, 980, 80, "Вопрос №");               // Number qest
    txDrawText (200, 90, 780, 160, "Столица России?");   // question
     txBitBlt(txDC(), 20, 203, 260, 275, ulyan);                          // picture 1
    txDrawText (20, 520, 280, 610, "Ульяновск");             // answer 1
     txBitBlt(txDC(), 352, 203, 285, 275, mockv);                         // picture 2
    txDrawText (335, 520, 660, 610, "Москва");               // answer 2
     txBitBlt(txDC(), 713, 203, 275, 275, piter);                         // picture 3
    txDrawText (720, 520, 990, 610, "Санкт-Питербург");      // answer 3

    //click answer 1 (left)
    if(txMouseButtons() == 1 &&
    txMouseX()>20 && txMouseX()<280 &&
    txMouseY()>520 && txMouseY() < 610 )
    {
        n_question ++;
    }


    //click answer 2 (middle)
    if(txMouseButtons() == 1 &&
    txMouseX()>352 && txMouseX()<660 &&
    txMouseY()>520 && txMouseY() < 610 )
    {
        n_question ++;
    }

     //click answer 3 (right)
    if(txMouseButtons() == 1 &&
    txMouseX()>720 && txMouseX()<990 &&
    txMouseY()>520 && txMouseY() < 610 )
    {
        n_question ++;
    }

    txEnd();
    txSleep(20);
    }









    return 0;
    }

