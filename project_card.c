#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <time.h>

 

typedef struct {

	int order;

	int number;

	char shape[3];

}trump;

char space[13][100] = {

 

		"┌──────────────┐ ",

 

		"│              │ ",

 

		"│              │ ",

 

		"│              │ ",

 

		"│              │ ",

 

		"│              │ ",

 

		"│              │ ",

 

		"│              │ ",

 

		"│              │ ",

 

		"│              │ ",

 

		"│              │ ",

 

		"│              │ ",

 

		"└──────────────┘ "

 

};

 

 

void make_card(trump m_card[]) {

	char shape[4][3] = { "a", "b", "c", "d" };

	for (int i = 0; i < 4; i++) {

		for (int j = i * 13; j < i * 13 + 13; j++) {

			m_card[j].order = i;

			strcpy(m_card[j].shape, shape[i]);

			int k = j % 13 + 1;

 

			if (k == 1)

				m_card[j].number = 'A';

			else if (k == 11)

				m_card[j].number = 'J';

			else if (k == 12)

				m_card[j].number = 'Q';

			else if (k == 13)

				m_card[j].number = 'K';

			else

				m_card[j].number = k;

 

		}

 

	}

}

 

void shuffle_card(trump m_card[]) {

	int rnd;

	trump temp;

	srand((unsigned)time(NULL));

	for (int i = 0; i < 52; i++) {

		rnd = rand() % 52;

		temp = m_card[rnd];

		m_card[rnd] = m_card[i];

		m_card[i] = temp;;

	}

}

 

 



void print_shape(trump card) {

	int i;

 	printf("%s\n", space[0]);

 

	if (card.number == 10) {

		printf("│ 10           │ \n");

	}

	else
		printf(card.number > 10 ? "│ %c            │ \n" : "│ %d            │ \n",card.number);

	if (strcmp(card.shape, "a") == 0) {

		for (i = 2; i < 6; i++)printf("%s\n", space[i]);

		printf("│      ♠       │ \n");

		for (i = 7; i < 13; i++)printf("%s\n", space[i]);

	}

	else if (strcmp(card.shape, "b") == 0) {

		for (i = 2; i < 6; i++)printf("%s\n", space[i]);

		printf("│      ◆       │ \n");

		for (i = 7; i < 13; i++)printf("%s\n", space[i]);

	}

	else if (strcmp(card.shape, "c") == 0) {

		for (i = 2; i < 6; i++)printf("%s\n", space[i]);

		printf("│      ♥       │ \n");

		for (i = 7; i < 13; i++)printf("%s\n", space[i]);

	}

	else if (strcmp(card.shape, "d") == 0) {

		for (i = 2; i < 6; i++)printf("%s\n", space[i]);

		printf("│      ♣       │ \n");

		for (i = 7; i < 13; i++)printf("%s\n", space[i]);

	}

}

 

void display_card(trump card[]) {// 인자로 show를 받음.

	int i;

	int j;

 

	trump card1 = card[0];

	trump card2 = card[1];

 

 

	

	print_shape(card1);
	print_shape(card2);

 

 

}

 

void card_graphic() {

	int i, j;

	trump card[52], show[2];

	make_card(card);

	shuffle_card(card);

	for (i = 0; i < 2; i++) show[i] = card[i];

 

	display_card(show);

}

 

void main() {

	card_graphic();

}
