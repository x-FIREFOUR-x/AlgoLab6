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


void GameBoard::set_parameters(int score ,int height, int width, bool g_with_pc)
{
   max_score = score;
   display_score();

   parameters(height, width, g_with_pc);
   finished = false;
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

    cards_hands1.set_y(height_side_px/10);
    cards_hands2.set_y(height_side_px - (height_side_px/10) - height_side_px/5);

    who_move_first = rand()%2 + 1;

    start_round();

}


void GameBoard::set_label(QLabel* counter, QLabel* score_player1, QLabel* score_player2, QLabel* score_max)
{
    Deck_counter = counter;
    Score_player1 = score_player1;
    Score_player2 = score_player2;
    Score_max = score_max;

}

void GameBoard::start_round()
{
    QGraphicsItem* ptr_carddeck = printer.print_cards_deck(scene);
    cards_deck.distribution(number_card_of_distrib, cards_hands1, cards_hands2);

    QString s = QString::number(cards_deck.get_amount_card_in_deck());
    Deck_counter->setText(s);

    pair<int,int> top_card = cards_deck.get_top_card();
    printer.print_top_card(top_card, scene);

    if (game_with_pc)
       cards_hands1.picture_backcards_hands(printer,scene);
    else
        cards_hands1.picture_cards_hands(printer, scene);
    cards_hands2.picture_cards_hands(printer, scene);

    current_player = who_move_first;

    int y1 = height_side_px/40;
    int y2 = height_side_px - height_side_px/20;
    int size = height_side_px/20;
    printer.print_marc_move(scene, current_player, width_side_px / 2, y1, y2, size);
}

void GameBoard::end_round()
{
     cards_deck.collect_cards(printer);
     cards_hands1.discard_cards();
     cards_hands2.discard_cards();
     printer.erase_marc_move(scene);
     printer.erase_converted_card();
}

void GameBoard::calculate_score()
{
    int score;
    score = cards_hands1.calculate_scorecards();
    score1 += score;
    score = cards_hands2.calculate_scorecards();
    score2 += score;
}
void GameBoard::display_score()
{
    Score_max->setText(QString::number(max_score));
    Score_player1->setText(QString::number(score1));
    Score_player2->setText(QString::number(score2));

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
      if(cards_hands1.get_count_cards() != 0 && cards_hands2.get_count_cards() != 0 && finished == false)
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

      if (score1 >= max_score || score2 >= max_score)
      {
          if(score2 >= max_score)
          {
              QString text = "ПЕРЕМІГ ПЕРШИЙ ГРАВЕЦЬ";
              QString title = "Ігра закінчилася";
              QMessageBox:: about(this,title,text);
              finished = true;
          }
          if(score1 >= max_score)
          {
              QString text = "ПЕРЕМІГ ДРУГИЙ ГРАВЕЦЬ";
              QString title = "Ігра закінчилася";
              QMessageBox:: about(this,title,text);
              finished = true;
          }
      }
      else
      {
          if (cards_hands1.get_count_cards() == 0 )
          {
              QString text = "В РАУНДІ ПЕРЕМІГ ПЕРШИЙ ГРАВЕЦЬ";
              QString title = "Ігра закінчилася";
              QMessageBox:: about(this,title,text);
              calculate_score();
              display_score();
              end_round();
              change_who_first_move();
              start_round();
          }
          if (cards_hands2.get_count_cards() == 0 )
          {
              QString text = "В РАУНДІ ПЕРЕМІГ ДРУГИЙ ГРАВЕЦЬ";
              QString title = "Ігра закінчилася";
              QMessageBox:: about(this,title,text);
              calculate_score();
              display_score();
              end_round();
              change_who_first_move();
              start_round();
          }


      }
}

void GameBoard::player_vs_computer(int mouse_x, int mouse_y)
{
    if(cards_hands1.get_count_cards() != 0 && cards_hands2.get_count_cards() != 0 && finished == false)
    {
        if(current_player ==1)
        {
            enemy_computer.set_date(cards_deck.get_deck_cards(), cards_deck.get_discarded_cards(), cards_hands1.get_cards(), cards_hands2.get_cards());
            enemy_computer.set_flags(put_three,put_four,put_eight,put_jocker,card_converted);
            pair<int,int> card = enemy_computer.mini_max();
            if(card.first == -1 && card.second == -1)
            {
                take_card_with_deck();
                display_count_deck();
            }
            else
            {
                comp_put_card_in_top(card);
                display_count_deck();
            }
            cards_hands1.picture_backcards_hands(printer,scene);
        }
        else
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


    }

    if (score1 >= max_score || score2 >= max_score)
    {
        if(score2 >= max_score)
        {
            QString text = "ВИ ПРОГРАЛИ";
            QString title = "Ігра закінчилася";
            QMessageBox:: about(this,title,text);
            finished = true;
        }
        if(score1 >= max_score)
        {
            QString text = "ВИ ПЕРЕМОГЛИ";
            QString title = "Ігра закінчилася";
            QMessageBox:: about(this,title,text);
            finished = true;
        }
    }
    else
    {
        if (cards_hands1.get_count_cards() == 0 )
        {
            cards_hands1.picture_cards_hands(printer,scene);
            //cards_hands1.set_picture(printer,scene);
            //QTimer::singleShot(1, &cards_hands1, &CardsHands::picture2_cards_hands);
            QString text = "В РАУНДІ ВИ ПРОГРАЛИ";
            QString title = "Ігра закінчилася";
            QMessageBox:: about(this,title,text);
            calculate_score();
            display_score();
            end_round();
            change_who_first_move();
            start_round();
        }
        if (cards_hands2.get_count_cards() == 0 )
        {
            cards_hands1.picture_backcards_hands(printer,scene);
            //cards_hands1.set_picture(printer,scene);
            //QTimer::singleShot(1, &cards_hands1, &CardsHands::picture2_cards_hands);
            QString text = "В РАУНДІ ВИ ПЕРЕМОГЛИ";
            QString title = "Ігра закінчилася";
            QMessageBox:: about(this,title,text);
            calculate_score();
            display_score();
            end_round();
            change_who_first_move();
            start_round();
        }
    }

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
         int numb;
         if(cards_deck.get_top_card().first == 15)
             numb = card_converted.first;
         else
             numb = cards_deck.get_top_card().first;

        if(current_player == 1)
        {
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
            for (int i = 0; i < numb; i++)
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

 void GameBoard::comp_put_card_in_top(pair<int,int> card1)
 {
     QGraphicsItem* ptr_chosen_card = cards_hands1.get_ptr_image_card(card1);
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
                 //cards_hands1.picture_cards_hands(printer, scene);
                 cards_hands1.picture_backcards_hands(printer, scene);
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

void GameBoard::change_who_first_move()
{
    if (who_move_first == 1)
        who_move_first =2;
    else
        who_move_first = 1;
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
            if(game_with_pc)
                cards_hands1.picture_backcards_hands(printer,scene);
            else
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
    int suit = -1;

    while (suit == -1 && (!game_with_pc || (game_with_pc && current_player == 2) ))
    {
        WindowSuit* suit_window = new WindowSuit(suit, this);
        suit_window->setWindowTitle("Останній гравець");
        suit_window->exec();
    }

    if (game_with_pc && current_player == 1)
    {
        suit = cards_hands1.suit_which_most();
    }

    card_converted.second = suit;
    card_converted.first = 8;
    printer.print_converted_card(card_converted,scene);
    change_move();
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
    while(!correct_choose && (!game_with_pc || (game_with_pc && current_player == 2)))
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

    if (game_with_pc && current_player == 1)
    {
          if(put_four)
           {
              suit = cards_deck.get_top_card().second;
              rank = 5;
              put_four = false;
           }
          else
          {
              rank = 8;
              suit = cards_hands1.suit_which_most();
              put_eight = true;
          }
    }

    card_converted.first = rank;
    card_converted.second = suit;
    assign_effect_card(card_converted);
    printer.print_converted_card(card_converted,scene);
    put_jocker = true;
}
