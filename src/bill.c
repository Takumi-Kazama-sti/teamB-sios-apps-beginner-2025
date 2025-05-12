#include <stdio.h>

struct Item {
    char name[10];
    int price;
    int stock;
};

int main() {
    struct Item items[] = {
        {"りんご", 100, 10},
        {"バナナ", 80, 20},
        {"みかん", 50, 15},
        {"お肉", 500, 5},
        {"牛乳", 300, 25},
        {"魚", 400, 30},
    };

    printf("お会計システム作成\n");
    printf("商品名と価格、在庫数を表示します。\n");
    printf("商品名\t価格\t在庫数\n");
    for (int i = 0; i < sizeof(items) / sizeof(items[0]); i++) {
        printf("%s\t%d円\t%d個\n", items[i].name, items[i].price, items[i].stock);
    }
    calculateBill(items, sizeof(items) / sizeof(items[0]));
    return 0;
}

void calculateBill(struct Item items[], int itemCount) {
  char inputName[10];
  int quantity, i, found = 0;

  printf("商品名を入力してください: ");
  scanf("%s", inputName);

  for (i = 0; i < itemCount; i++) {
    if (strcmp(items[i].name, inputName) == 0) {
      found = 1;
      printf("個数を入力してください: ");
      scanf("%d", &quantity);

      if (quantity > items[i].stock) {
        printf("在庫が足りません。在庫数: %d\n", items[i].stock);
      } else {
        int total = quantity * items[i].price;
        printf("合計金額: %d円\n", total);
        items[i].stock -= quantity;
      }
      break;
    }
  }

  if (!found) {
    printf("商品が見つかりません。\n");
  }
}