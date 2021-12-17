#include "gameboard.h"
#include <iostream>

#include <unistd.h>
#include <QMouseEvent>
#include <QDebug>
#include <QMessageBox>
#include <QTimer>
#include <QBrush>
#include <QPixmap>

GameBoard::GameBoard(QWidget *parent):
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

    pair<int,int> top_card = cards_deck.get_top_card();
    printer.print_top_card(top_card, scene);

    cards_hands1.set_y(height_side_px/10);
    cards_hands2.set_y(height_side_px - (height_side_px/10) - height_side_px/5);

    cards_hands1.picture_cards_hands(printer, scene);
    cards_hands2.picture_cards_hands(printer, scene);

}

void GameBoard::set_parameters(int height, int width, bool g_with_pc)
{
   parameters(height, width, g_with_pc);
}

void GameBoard::set_parameters(int height, int width, bool g_with_pc, bool pc_first, int level_dif)
{
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
          }
          else
          {
              if(current_player == 1)
              {

              }
              else
              {

              }
          }

      }
      else
      {
            if(cards_hands1.get_count_cards() == 0)
            {
                QString text = "ПЕРЕМІГ ПЕРШИЙ ГРАВЕЦЬ";
                QString title = "Ігра закінчилася";
                QMessageBox:: about(this,title,text);
            }
            else
            {
                QString text = "ПЕРЕМІГ ДРУГИЙ ГРАВЕЦЬ";
                QString title = "Ігра закінчилася";
                QMessageBox:: about(this,title,text);
            }
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
     if (cards_deck.is_card_no_in_players())
     {
         if(current_player == 1)
         {
             pair<int,int> new_card = cards_deck.take_card();
             cards_hands1.give_card(new_card);
             cards_hands1.picture_cards_hands(printer,scene);
             current_player =2;
         }
         else
         {
             pair<int,int> new_card = cards_deck.take_card();
             cards_hands2.give_card(new_card);
             cards_hands2.picture_cards_hands(printer,scene);
             current_player = 1;
         }

         if(!cards_deck.is_card_no_in_players())
         {
             printer.erase_cards_deck();
         }
     }
 }
