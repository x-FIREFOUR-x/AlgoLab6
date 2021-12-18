#include "gameboard.h"
#include <iostream>

#include <unistd.h>
#include <QMouseEvent>
#include <QDebug>
#include <QMessageBox>
#include <QTimer>
#include <QBrush>
#include <QPixmap>

GameBoard::GameBoard( QWidget *parent):
    QGraphicsView(parent)
{
    scene = new QGraphicsScene;
    setScene(scene);

    current_player = 1;
}

GameBoard::~GameBoard()
{
    delete scene;
}

void GameBoard::parameters(int height, int width, bool g_with_pc)
{   
    height_side_px = height;
    width_side_px = width;
    game_with_pc = g_with_pc;

    finished = false;

    int height_card = height/5;
    int width_card = height_card * 0.75;
    printer.set_side(width_card, height_card);

    int x_deck = width_side_px / 20;
    int y = height_side_px/5 + 2*height_side_px/10;
    int x_top = width_side_px / 2;
    printer.set_coordinate(x_deck, y, x_top, y);

    setFixedSize(width_side_px, height_side_px);
    QPixmap image_board(":/image/PNG-cards/table.png");
    image_board = image_board.scaled(this->width(),this->height());
    scene->setSceneRect(0,0,image_board.width(),image_board.height());
    scene->setBackgroundBrush(image_board);

    QGraphicsItem* ptr_carddeck = printer.print_cards_deck(scene);

    cards_deck.distribution(number_card_of_distrib, cards_hands1, cards_hands2);

    QString s = QString::number(cards_deck.get_amount_card_in_deck());
    Deck_counter->setText(s);

    pair<int,int> top_card = cards_deck.get_top_card();
    printer.print_top_card(top_card, scene);

    cards_hands1.set_y(height_side_px/10);
    cards_hands2.set_y(height_side_px - (height_side_px/10) - height_side_px/5);

    cards_hands1.picture_cards_hands(printer, scene);
    cards_hands2.picture_cards_hands(printer, scene);

    int y1 = height_side_px/40;
    int y2 = height_side_px - height_side_px/20;
    int size = height_side_px/20;
    printer.print_marc_move(scene, current_player, width_side_px / 2, y1, y2, size);

}

void GameBoard::set_parameters(QLabel* counter, int height, int width, bool g_with_pc)
{
   Deck_counter = counter;
   parameters(height, width, g_with_pc);
}

void GameBoard::set_parameters(QLabel* counter, int height, int width, bool g_with_pc, bool pc_first, int level_dif)
{
    Deck_counter = counter;
    parameters(height, width, g_with_pc);

    computer_first = pc_first;
    difficulty = level_dif;
    level_recur = difficulty;
    finished = false;

    if(pc_first)
    {
        //PainterCube::paint_first_cube(scene, 1 * size_cells, 0 * size_cells, size_cells, size_cells*2);
        //board.set_adj_cells(1, 9, current_player);
        //current_player = 2;
    }
}

void GameBoard::mousePressEvent(QMouseEvent *event)
{
    int mouse_x = event->position().x();
    int mouse_y = event->position().y();

    if(game_with_pc)
    {
        player_vs_computer(mouse_x, mouse_y);
    }
    else
    {
        player_vs_player(mouse_x, mouse_y);
    }

}

void GameBoard::player_vs_player(int mouse_x, int mouse_y)
{
      if(cards_hands1.get_count_cards() != 0 && cards_hands2.get_count_cards() != 0 )
      {
          if (is_click_on_deck(mouse_x, mouse_y))
          {
              take_card_with_deck();
              display_count_deck();
          }
          else
          {
              put_card_in_top(mouse_x, mouse_y);
              display_count_deck();
          }

      }

      if(cards_hands1.get_count_cards() == 0)
      {
          QString text = "ПЕРЕМІГ ПЕРШИЙ ГРАВЕЦЬ";
          QString title = "Ігра закінчилася";
          QMessageBox:: about(this,title,text);
      }
      if(cards_hands2.get_count_cards() == 0)
      {
          QString text = "ПЕРЕМІГ ДРУГИЙ ГРАВЕЦЬ";
          QString title = "Ігра закінчилася";
          QMessageBox:: about(this,title,text);
      }

}

void GameBoard::player_vs_computer(int mouse_x, int mouse_y)
{
    if(computer_first)
        player_move_second(mouse_x,mouse_y);
    else
        player_move_first(mouse_x,mouse_y);

}

void GameBoard::player_move_second(int mouse_x, int mouse_y)
{
   /* if(board.is_move(current_player))
    {

            // хід гравця
        if(current_player == 2)
        {
                int row_cells = mouse_y / size_cells;
                int column_cell1;
                int column_cell2;

                    // визначення номерів двох вибраних клітинок
                if (mouse_x % size_cells < size_cells/2)
                {
                    column_cell2 = mouse_x / size_cells;
                    column_cell1 = column_cell2-1;
                }
                else
                {
                    column_cell1 = mouse_x / size_cells;
                    column_cell2 = column_cell1+1;
                }

                int index1 =  row_cells * amount_point  + column_cell1;
                int index2 =  row_cells * amount_point  + column_cell2;

                    // перевірка можливості фарбування вибраних двох клітинок
                if ((index1/amount_point == index2/amount_point ) && board.is_cell_empty(index1) && board.is_cell_empty(index2))
                {
                    PainterCube::paint_second_cube(scene, column_cell1 * size_cells, row_cells * size_cells, size_cells*2, size_cells);
                    board.set_adj_cells(index1, index2, current_player);
                    current_player = 1;

                    QTimer::singleShot(time_deley, this, &GameBoard::pc_move_first);
                }

        }

    }

    else
    {
        if (player_win)
        {
            QString text = "ТИ ПЕРЕМІГ";
            QString title = "Ігра закінчилася";
            QMessageBox:: about(this,title,text);
        }
        else
        {
            QString text = "ТИ ПРОГРАВ";
            QString title = "Ігра закінчилася";
            QMessageBox:: about(this,title,text);
        }
    }*/
}

void GameBoard::pc_move_first()
{
   /* if(board.is_move(current_player))
    {
        // хід компютера
        EnemyComputer computer(board, level_recur, 1, 2, board.get_size(), board.get_amount_point_side());

        pair<int,int> inds = computer.alfa_beta_pruning();
        int index1;
        int index2;
        if(inds.first < inds.second)
        {
            index1 = inds.first;
            index2 = inds.second;
        }
        else
        {
            index1 = inds.second;
            index2 = inds.first;
        }
        int column = index1 % amount_point;
        int row = index1 / amount_point;

        PainterCube::paint_first_cube(scene, column * size_cells, row * size_cells, size_cells, size_cells*2);
        board.set_adj_cells(index1, index2, current_player);
        current_player = 2;

        if(!board.is_move(current_player))
        {
            QString text = "ТИ ПРОГРАВ";
            QString title = "Ігра закінчилася";
            QMessageBox:: about(this,title,text);
            finished = true;
            player_win = false;
        }
    }
    else
    {
        QString text = "ТИ ПЕРЕМІГ";
        QString title = "Ігра закінчилася";
        QMessageBox:: about(this,title,text);
        finished = true;
        player_win = true;
    }*/
}

void GameBoard::player_move_first(int mouse_x, int mouse_y)
{
    /*if(board.is_move(current_player))
    {
        if (current_player == 1)
        {
            // хід гравця
            int column_cells = mouse_x / size_cells;
            int row_cell1;
            int row_cell2;

                // визначення номерів двох вибраних клітинок
            if (mouse_y % size_cells < size_cells/2)
            {
                row_cell2 = mouse_y / size_cells;
                row_cell1 = row_cell2-1;
            }
            else
            {
                row_cell1 = mouse_y / size_cells;
                row_cell2 = row_cell1+1;
            }

            int index1 =  row_cell1 * amount_point  + column_cells;
            int index2 =  row_cell2 * amount_point  + column_cells;

                // перевірка можливості фарбування вибраних двох клітинок
            if (row_cell1 >= 0 && row_cell2 < amount_point && board.is_cell_empty(index1) && board.is_cell_empty(index2))
            {
                PainterCube::paint_first_cube(scene, column_cells * size_cells, row_cell1 * size_cells, size_cells, size_cells*2);
                board.set_adj_cells(index1, index2, current_player);
                current_player = 2;

                QTimer::singleShot(time_deley, this, &GameBoard::pc_move_second);

            }
        }

    }
    else
    {
        if (player_win)
        {
            QString text = "ТИ ПЕРЕМІГ";
            QString title = "Ігра закінчилася";
            QMessageBox:: about(this,title,text);
        }
        else
        {
            QString text = "ТИ ПРОГРАВ";
            QString title = "Ігра закінчилася";
            QMessageBox:: about(this,title,text);
        }

    }*/
}

void GameBoard::pc_move_second()
{
   /* if(board.is_move(current_player))
    {
        // хід компютера
        EnemyComputer computer(board, level_recur, 2, 1, board.get_size(), board.get_amount_point_side());

        pair<int,int> inds = computer.alfa_beta_pruning();
        int index1;
        int index2;
        if(inds.first <inds.second)
        {
            index1 = inds.first;
            index2 = inds.second;
        }
        else
        {
            index1 = inds.second;
            index2 = inds.first;
        }
        int column = index1 % amount_point;
        int row = index1 / amount_point;

        PainterCube::paint_second_cube(scene, column * size_cells, row * size_cells, size_cells*2, size_cells);
        board.set_adj_cells(index1, index2, current_player);
        current_player = 1;

        if(!board.is_move(current_player))
        {
            QString text = "ТИ ПРОГРАВ";
            QString title = "Ігра закінчилася";
            QMessageBox:: about(this,title,text);
            finished = true;
            player_win = false;
        }
    }
    else
    {
        QString text = "ТИ ПЕРЕМІГ";
        QString title = "Ігра закінчилася";
        QMessageBox:: about(this,title,text);
        finished = true;
        player_win = true;
    }*/
}

void GameBoard::resizeEvent(QResizeEvent *event)
{
    fitInView(sceneRect(), Qt::IgnoreAspectRatio);
}

 bool GameBoard::is_click_on_deck(int mouse_x, int mouse_y)
 {
     int x_cards_deck = printer.get_x_cards_deck();
     int y_cards_deck = printer.get_y_cards_deck();
     int width_card = printer.get_width();
     int height_card = printer.get_height();

     if ((mouse_x <= x_cards_deck + width_card) && (mouse_x >= x_cards_deck))
     {
         if ((mouse_y <= y_cards_deck + height_card) && (mouse_y >= y_cards_deck))
         {
             return true;
         }
     }
     return false;
 }

 void GameBoard::take_card_with_deck()
 {
     if (put_four)
     {
            // ефект четвьорки
        if(current_player == 1)
        {
            int numb;
            if(cards_deck.get_top_card().first == 15)
                numb = card_converted.first;
            else
                numb = cards_deck.get_top_card().first;

            for (int i = 0; i < numb; i++)
            {
                if (cards_deck.get_amount_card_in_deck() + cards_deck.get_amount_descarded_card()  > 0)
                {
                    pair<int,int> new_card = cards_deck.take_card();
                    cards_hands1.give_card(new_card);
                    cards_hands1.picture_cards_hands(printer,scene);
                }
            }
            put_four = false;
            change_move();
        }
        else
        {
            for (int i = 0; i < cards_deck.get_top_card().first; i++)
            {
                if (cards_deck.get_amount_card_in_deck() + cards_deck.get_amount_descarded_card()  > 0)
                {
                    pair<int,int> new_card = cards_deck.take_card();
                    cards_hands2.give_card(new_card);
                    cards_hands2.picture_cards_hands(printer,scene);
                }
            }
            put_four = false;
            change_move();
        }
     }
     else
     {
         if (cards_deck.is_card_no_in_players())
         {
             if(current_player == 1)
             {
                 pair<int,int> new_card = cards_deck.take_card();
                 cards_hands1.give_card(new_card);
                 cards_hands1.picture_cards_hands(printer,scene);
                 current_player =2;
                 printer.print_change_move(scene, current_player);
             }
             else
             {
                 pair<int,int> new_card = cards_deck.take_card();
                 cards_hands2.give_card(new_card);
                 cards_hands2.picture_cards_hands(printer,scene);
                 current_player = 1;
                 printer.print_change_move(scene, current_player);
             }
         }
     }
     if(!cards_deck.is_card_no_in_players())
     {
         printer.erase_cards_deck();
     }
 }
 void GameBoard::put_card_in_top(int mouse_x, int mouse_y)
 {
     QGraphicsItem* ptr_chosen_card = itemAt(mouse_x,mouse_y);
     pair<int,int> card;

     if(current_player == 1)
     {
         bool succes_chosen = cards_hands1.get_chosen_card(ptr_chosen_card, card);
         if (succes_chosen)
         {
             if(can_put_chosen_card(card) || put_three)
             {
                 if (put_three)
                     put_three = false;

                 cards_hands1.pull_card_with_hands(ptr_chosen_card);
                 assign_effect_card(card);
                 cards_deck.put_card(card, scene, printer);
                 ptr_chosen_card = nullptr; 
                 cards_hands1.picture_cards_hands(printer, scene);
                 printer.print_top_card(card, scene);
                 scene->update();
             }

         }

     }
     else
     {
         bool succes_chosen = cards_hands2.get_chosen_card(ptr_chosen_card, card);
         if (succes_chosen)
         {
             if(can_put_chosen_card(card) || put_three)
             {
                 if (put_three)
                     put_three = false;

                cards_hands2.pull_card_with_hands(ptr_chosen_card);
                assign_effect_card(card);
                cards_deck.put_card(card, scene, printer);
                ptr_chosen_card = nullptr;

                cards_hands2.picture_cards_hands(printer, scene);
                printer.print_top_card(card, scene);
                scene->update();
             }
         }
     }
 }

 bool GameBoard::can_put_chosen_card(pair<int,int> card)
 {
     bool correct_move = false;
     pair<int,int> top_card;
     if(put_jocker)
     {
         top_card = card_converted;
     }
     else
     {
         top_card = cards_deck.get_top_card();
     }


            // перевірка чи вибрана карта одного значення чи масті з верхньою
     if ((card.first == top_card.first) || (card.second == top_card.second))
     {
             correct_move = true;
     }

     if (top_card.first == 15 && put_jocker == false)         //якщо лежить джокер
     {
         correct_move = false;
         if(top_card.second == 0 && (card.second == 0 || card.second == 3 ))
             correct_move = true;

         if(top_card.second == 1 && (card.second == 1 || card.second == 2 ))
             correct_move = true;
     }

     if(top_card.first == 8 && put_eight)   //якщо лежить 8
     {
          correct_move = false;
          if (card.second == card_converted.second)
          {
              correct_move = true;
              put_eight = false;
              printer.erase_converted_card();
          }

     }

     if (card.first == 8 || card.first == 15)       // перевірка чи вибрана карта 8 чи джокер
     {
         correct_move = true;
     }

     if (put_four)              // якщо працює ефект четвьорки
     {
         correct_move = false;
         if (((card.first == (top_card.first + 1)) && (card.second == top_card.second)) || card.first == 15)
         {
             correct_move = true;
             if(card.first != 15)
                put_four = false;
         }

     }

     if(put_three)
     {
         correct_move = true;
         put_three = false;
     }

     if(put_jocker && correct_move == true && card.first != 15)
     {
         put_jocker = false;
         printer.erase_converted_card();
     }


    return correct_move;
 }

 void GameBoard::change_move()
 {
     if (current_player == 1)
     {
         current_player = 2;
         printer.print_change_move(scene, current_player);
     }
     else
     {
         current_player = 1;
         printer.print_change_move(scene, current_player);
     }
 }

void GameBoard::display_count_deck()
{
    if (cards_deck.get_amount_card_in_deck() > 0)
    {
        QString s = QString::number(cards_deck.get_amount_card_in_deck());
        Deck_counter->setText(s);
    }
    else
    {
        int count = cards_deck.get_amount_card_in_deck() + cards_deck.get_amount_descarded_card();
        QString s = QString::number(count);
        Deck_counter->setText(s);
    }

}

void GameBoard::assign_effect_card(pair<int,int> card)
{
    switch (card.first)
    {
        case 2: effect_two(); break;
        case 3: effect_three(); break;
        case 4: effect_four() ;break;
        case 8: effect_eight(); break;
        case 11: effect_jack(); break;
        case 15: effect_joker(); break;
        default: change_move();
    }
}

void GameBoard::effect_two()
{
    if (current_player == 1)
    {
        current_player = 2;
        if (cards_deck.get_amount_card_in_deck()+cards_deck.get_amount_descarded_card() > 0)
        {
            pair<int,int> new_card = cards_deck.take_card();
            cards_hands2.give_card(new_card);
            cards_hands2.picture_cards_hands(printer,scene);
        }
        current_player =1;
    }
    else
    {
        current_player =1;
        if (cards_deck.get_amount_card_in_deck()+cards_deck.get_amount_descarded_card() > 0)
        {
            pair<int,int> new_card = cards_deck.take_card();
            cards_hands1.give_card(new_card);
            cards_hands1.picture_cards_hands(printer,scene);
        }
        current_player =2;
    }
    if(!cards_deck.is_card_no_in_players())
    {
        printer.erase_cards_deck();
    }
}
void GameBoard::effect_three()
{
    put_three = true;
}
void GameBoard::effect_four()
{
    change_move();
    put_four = true;
}
void GameBoard::effect_eight()
{
    change_move();

    int suit = -1;
    while (suit == -1)
    {
        WindowSuit* suit_window = new WindowSuit(suit, this);
        suit_window->setWindowTitle("Останній гравець");
        suit_window->exec();
    }

    card_converted.second = suit;
    card_converted.first = 8;
    printer.print_converted_card(card_converted,scene);
    put_eight = true;
}
void GameBoard::effect_jack()
{
    if (current_player == 1)
    {
        current_player =1;
        printer.print_change_move(scene, current_player);
    }
    else
    {
        current_player = 2;
        printer.print_change_move(scene, current_player);
    }


}
void GameBoard::effect_joker()
{

    int rank;
    int suit;
    bool correct_choose = false;
    while(!correct_choose)
    {
        rank = -1;
        suit = -1;
        while (rank == -1)
        {
            WindowRank* rank_window = new WindowRank(rank, this);
            rank_window->setWindowTitle("Останній гравець");
            rank_window->exec();
        }

        while (suit == -1)
        {
            WindowSuit* suit_window = new WindowSuit(suit, this);
            suit_window->setWindowTitle("Останній гравець");
            suit_window->exec();
        }
       if( can_put_chosen_card(pair<int,int>(rank,suit)))
           correct_choose = true;
    }

    //change_move();
    card_converted.first = rank;
    card_converted.second = suit;
    assign_effect_card(card_converted);
    printer.print_converted_card(card_converted,scene);
    put_jocker = true;
}
