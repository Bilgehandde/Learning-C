#include <stdio.h>
#include <stdbool.h>

// Fonksiyon prototipleri
void initialize_Game_Board(int size, char (*board)[size]);
void show_Game_Board(int size, char (*board)[size]);
int update_Game_Board(int position, char symbol, int size, char (*board)[size]);
int check_for_Win(int size, char (*board)[size]);
void start_Game();
void Menu();
void show_Game_Rules();
void write_Score_To_File(int winner);
void show_ScoreBoard();

int player1_score = 0;
int player2_score = 0;
int beraberlik = 0;

int main() {
	while (1)
	{
		Menu();
	}
    return 0;
}
void Menu() {
    int cho;
    printf("Tic-Tac-Toe Oyunu\n");
    printf("1. Oyunu Baslat\n");
    printf("2. Oyun Kurallarini Goster\n");
    printf("3. Skor Tablosunu Goster\n");
    printf("4. Skoru Resetle\n");
    printf("Seciminizi yapin: ");
    scanf("%d", &cho);

    switch(cho) {
        case 1:
            start_Game();
            break;
        case 2:
            show_Game_Rules();
            break;
        case 3:
            show_ScoreBoard();
            break;
        case 4:
            player1_score = 0;
            player2_score = 0;
            printf("Skorlar sifirlandi.\n\n");
            break;
        default:
            printf("Gecersiz secim. Lutfen tekrar deneyin.\n");
            Menu();
    }
}
void show_Game_Rules() {
    printf("\n\n--KURALLAR--\nTic-Tac-Toe, iki oyuncu arasinda oynanan klasik bir oyunudur. Oyun tahtasi 3x3 - 9x9 boyutunda olabilir.\n");
    printf("Oyuncular sirayla tahta hucrelerine simgelerini, genellikle X veya O, yerlestirirler.\n");
    printf("Bir oyuncu uc simgeyi yatay, dikey veya capraz olarak bir araya getirerek bir satir olusturana kadar oyun devam eder.\n\n");
}
void start_Game() {
    // X-O-X-O þeklinde sýra deðiþimi yaparak oyunu baþlat
    int size;
    printf("\nTahta boyutunu secin (3 veya 9): ");
    scanf("%d", &size);
    if( size != 3 && size != 9){
    	printf("\nLutfen 3 veya 9 giriniz!\n\n");
    	start_Game();
	}

    char board[size][size];
    initialize_Game_Board(size, board);
    int player = 1;

    int move;
    int winner = 0;
    while (!winner) {
        show_Game_Board(size, board);
        printf("%d. Oyuncu icin pozisyonu girin: ", player);
        scanf("%d", &move);
        
        char symbol = (player == 1) ? 'O' : 'X';
        if (update_Game_Board(move, symbol, size, board)) {
            winner = check_for_Win(size, board);
            if (winner) {
                show_Game_Board(size, board);
                if (winner == -1) {
                	char devam;
                    printf(" ----- Berabere ----- \n\n");
                    beraberlik++;
                } 
				else 
            		printf("\nTebrikler %d. Oyuncu kazandi\n\n", winner);
            		if (winner == 1 )
            			player1_score++;
            		if (winner == 2)
            			player2_score++;	
            } 
			else 
            	player = (player == 1) ? 2 : 1;
        }
    }
}
void initialize_Game_Board(int size, char (*board)[size]) {
    // Oyun tahtasýný baþlat
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            board[i][j] = ' ';
        }
    }
}
void show_Game_Board(int size, char (*board)[size]) {
    // Oyun tahtasýný göster
    printf("\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf(" %c ", board[i][j]);
            if (j < size - 1) printf("|");
        }
        printf("\n");
        if (i < size - 1) {
            for (int k = 0; k < size * 4 - 1; k++) printf("-");
            printf("\n");
        }
    }
}
int update_Game_Board(int position, char symbol, int size, char (*board)[size]) {
    // Oyuncunun hamlesiyle oyun tahtasýný güncelle
    int row = (position - 1) / size;
    int col = (position - 1) % size;
    
    if (position < 1 || position > size * size || board[row][col] != ' ') {
        // Geçersiz hamle
        printf("Gecersiz hamle.Lutfen tekrar deneyin.\n");
        return 0;
    }
    board[row][col] = symbol;
    return 1;
}
int check_for_Win(int size, char (*board)[size]) {
    // Kazananý kontrol et
    // Satýrlarý kontrol et
for (int i = 0; i < size; i++) {
    // Sütunlarýn sonuna kadar git
    for (int j = 0; j <= size - 3; j++) {
        // Satýrdaki 3 ardýþýk hücreyi kontrol et
        //  Tek matristen ilerlemek içinde  *(array + i) pointerýný kullanarakta ilerlenebilir.
        if (board[i][j] != ' ' && board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2]) {
            // Eðer ayný semboller varsa, kazanan oyuncuyu döndür
            if (board[i][j] == 'O') return 1; // Oyuncu 1 kazandý
            else return 2; // Oyuncu 2 kazandý
        }
        // Sütunlarda 3 ardýþýk hücreyi kontrol et
        if (board[j][i] != ' ' && board[j][i] == board[j + 1][i] && board[j][i] == board[j + 2][i]) {
            // Eðer ayný semboller varsa, kazanan oyuncuyu döndür
            if (board[j][i] == 'O') return 1; // Oyuncu 1 kazandý
            else return 2; // Oyuncu 2 kazandý
        }
    }
}

// Diagonal kontrolleri
for (int i = 0; i <= size - 3; i++) {
    for (int j = 0; j <= size - 3; j++) {
        // Sol üstten sað alta doðru diyagonali kontrol et
        if (board[i][j] != ' ' && board[i][j] == board[i + 1][j + 1] && board[i][j] == board[i + 2][j + 2]) {
            // Eðer ayný semboller varsa, kazanan oyuncuyu döndür
            if (board[i][j] == 'O') return 1; // Oyuncu 1 kazandý
            else return 2; // Oyuncu 2 kazandý
        }
        // Sað üstten sol alta doðru diyagonali kontrol et
        if (board[i][j + 2] != ' ' && board[i][j + 2] == board[i + 1][j + 1] && board[i][j + 2] == board[i + 2][j]) {
            // Eðer ayný semboller varsa, kazanan oyuncuyu döndür
            if (board[i][j + 2] == 'O') return 1; // Oyuncu 1 kazandý
            else return 2; // Oyuncu 2 kazandý
        }
    }
}
    // Beraberlik durumunu kontrol et
    bool draw = true;
    // Oyun tahtasýndaki tüm hücreleri dolaþarak boþ hücre olup olmadýðýný kontrol etmek için iki döngü oluþturuldu.
	for (int i = 0; i < size; i++) {
    	for (int j = 0; j < size; j++) {
        	// Eðer bir boþ hücre bulunursa, draw deðiþkeni false olarak iþaretlenir ve iç döngüden çýkýlýr.
        	if (board[i][j] == ' ') {
            	draw = false;
            	break;
        		}
    	}
	}
    if (draw) return -1; // Berabere
    return 0; // Henüz bir kazanan yok
}
void show_ScoreBoard() {
    printf("\nSkor Tablosu\n");
    printf("Oyuncu 1: %d\n", player1_score);
    printf("Oyuncu 2: %d\n\n", player2_score);
}
