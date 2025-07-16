# Minesweeper Game (C) EN/TR

\<p align="center"\>
\<img src="[https://img.shields.io/badge/Language-C-blue.svg](https://img.shields.io/badge/Language-C-blue.svg)" alt="C Language"\>
\<img src="[https://img.shields.io/badge/Status-Completed-brightgreen.svg](https://img.shields.io/badge/Status-Completed-brightgreen.svg)" alt="Project Status"\>
\<img src="[https://img.shields.io/badge/License-MIT-blue.svg](https://img.shields.io/badge/License-MIT-blue.svg)" alt="License"\>
\</p\>

## English Description

This project is a terminal-based C implementation of the classic Minesweeper game, developed as an assignment for the CSE102 Computer Programming course. The game features a randomly generated NxN board with randomly placed mines. The user attempts to uncover cells while avoiding mines, with the number of adjacent mines displayed for each uncovered cell. The game includes an "undo" command that reverses the most recent move using a custom stack data structure.

### Features

  * **Random Board Generation:** At the start of the program, a random board size N (between 2 and 10) is generated.
  * **Random Mine Placement:** Some cells are randomly designated as mines on the board.
  * **Interactive Gameplay:** Players can enter coordinates (`row col`) to uncover cells.
  * **Mine Counter:** The number of mines adjacent to each uncovered cell is shown (0-8).
  * **Game Over Condition:** If the player hits a mine, the game ends with a "BOOM\! You hit a mine. Game Over." message.
  * **Undo Functionality:** Players can type `undo` to reverse their most recent move. This feature is implemented using a custom Last-In, First-Out (LIFO) stack data structure.
  * **Dynamic Board Display:** After each move, the current state of the board is shown using ASCII characters: `#` for hidden cells, `0-8` for revealed cells (indicating nearby mines).

### File Outputs

  * **`map.txt`**: The automatically generated game board is saved to this file at the start of the game.
  * **`moves.txt`**: At the end of the game (or after each move with the current code), the sequence of valid moves is saved in a formatted output file. The format is `Move X: (Row R, Col C)` and `Total Moves: N`.

### Missing / Future Improvements

  * **Recursive Flood Fill:** The assignment requires that if a user selects a cell with zero adjacent mines, all neighboring cells should automatically be revealed using a recursive flood fill. This functionality is **not yet implemented** in the current code.

### How to Compile and Run

To compile and run this program, you will need a C compiler (like GCC).

1.  **Save the code:** Save the provided C code as `minesweeper.c` (or `your_program.c` as per assignment requirements).
2.  **Compile:** Open your terminal or command prompt, navigate to the directory where you saved the file, and compile using the following command:
    gcc --ansi your_program.c -o your_program

    *(Note: The assignment specifically requests `--ansi`. Replace `your_program.c` with `emircan_badur.c` if that's your filename, and `your_program` with `minesweeper` for the executable name.)*
3.  **Run:** Execute the compiled program:
    ./your_program

    *(Replace `your_program` with the actual executable name, e.g., `./minesweeper`.)*

-----

## Türkçe Açıklama

Bu proje, CSE102 Bilgisayar Programlama dersi için geliştirilmiş klasik Mayın Tarlası oyununun terminal tabanlı bir C uygulamasıdır. Oyun, rastgele oluşturulmuş NxN boyutunda bir tahta ve rastgele yerleştirilmiş mayınlar içerir. Kullanıcı, mayınlardan kaçınarak hücreleri açmaya çalışır ve her açılan hücre için komşu mayın sayısı gösterilir. Oyun, özel bir yığın (stack) veri yapısı kullanarak en son hamleyi geri alan bir "undo" (geri al) komutu içerir.

### Özellikler

  * **Rastgele Tahta Oluşturma:** Programın başlangıcında rastgele bir N tahta boyutu (2 ile 10 arasında) oluşturulur.
  * **Rastgele Mayın Yerleşimi:** Tahtadaki bazı hücrelere rastgele mayınlar yerleştirilir.
  * **Etkileşimli Oynanış:** Oyuncular, hücreleri açmak için koordinatları (`satır sütun` örn: "3 5") girerler.
  * **Mayın Sayacı:** Açılan her hücre için komşu mayın sayısı gösterilir (0-8).
  * **Oyun Bitiş Durumu:** Oyuncu bir mayına basarsa, oyun "BOOM\! You hit a mine. Game Over." (BOOM\! Bir mayına bastınız. Oyun Bitti.) mesajıyla sona erer.
  * **Geri Alma İşlevi:** Oyuncular, en son hamlelerini geri almak için `undo` yazabilirler. Bu özellik, son giren ilk çıkar (LIFO) prensibine sahip özel bir yığın veri yapısı kullanılarak uygulanmıştır.
  * **Dinamik Tahta Görüntüsü:** Her hamleden sonra, tahtanın mevcut durumu ASCII karakterler kullanılarak gösterilir: gizli hücreler için `#`, açılmış hücreler için (yakındaki mayın sayısını belirten) `0-8`.

### Dosya Çıktıları

  * **`map.txt`**: Otomatik olarak oluşturulan oyun tahtası, oyunun başlangıcında bu dosyaya kaydedilir.
  * **`moves.txt`**: Oyunun sonunda (veya mevcut kod ile her hamleden sonra), geçerli hamle dizisi biçimlendirilmiş bir çıktı dosyasına kaydedilir. Biçim `Move X: (Satır R, Sütun C)` ve `Toplam Hamle: N` şeklindedir.

### Eksik / Gelecek Geliştirmeler

  * **Özyinelemeli Sel Doldurma (Recursive Flood Fill):** Ödev, kullanıcının sıfır komşu mayına sahip bir hücreyi seçmesi durumunda, tüm komşu hücrelerin özyinelemeli sel doldurma kullanılarak otomatik olarak açılmasını gerektirmektedir. Bu işlevsellik, mevcut kodda **henüz uygulanmamıştır**.

### Derleme ve Çalıştırma

Bu programı derlemek ve çalıştırmak için bir C derleyicisine (örn. GCC) ihtiyacınız olacaktır.

1.  **Kodu Kaydet:** Sağlanan C kodunu `minesweeper.c` (veya ödev gereksinimlerine göre `your_program.c`) olarak kaydedin.
2.  **Derle:** Terminalinizi veya komut istemcinizi açın, dosyayı kaydettiğiniz dizine gidin ve aşağıdaki komutu kullanarak derleyin:
    gcc --ansi your_program.c -o your_program

    *(Not: Ödev özellikle `--ansi` kullanılmasını istemektedir. Eğer dosya adınız `emircan_badur.c` ise, `your_program.c` yerine `emircan_badur.c` yazın ve çalıştırılabilir dosya adı için `your_program` yerine `minesweeper` kullanabilirsiniz.)*
3.  **Çalıştır:** Derlenmiş programı çalıştırın:
    ./your_program

    *(`your_program` yerine gerçek çalıştırılabilir dosya adını, örn. `./minesweeper` yazın.)*
