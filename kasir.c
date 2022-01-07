#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char yes[3] = "";
    char isMember[3] = "";
    char *barang[5] = {"Beras", "Sabun", "Minyak", "Roti", "Kopi ABC"};
    char *barang_dipilih[30];
    int pilihan, uang, kembalian, total, i, j, banyak, jumlah[30], harga_dipilih[30];
    int harga[5] = {15000, 5000, 6000, 7000, 2500};
    int isTrue = 1;

    printf("======= Kasir Koperasi Mini ======= \n");
    printf("Persediaan\n");
    printf("1. Beras (1 liter) Rp15.000\n");
    printf("2. Sabun Rp5.000\n");
    printf("3. Minyak Rp6.000\n");
    printf("4. Roti Rp7.000\n");
    printf("5. Kopi ABC Rp2.500\n");

    i = 0;
    total = 0;
    while (1)
    {
    pilih_barang:
        printf("\nMasukkan pilihan anda (1-5): ");
        scanf("%d", &pilihan);
        pilihan = pilihan - 1;
        barang_dipilih[i] = barang[pilihan];
        harga_dipilih[i] = harga[pilihan];

        if ((pilihan + 1 > 5) || (pilihan + 1 < 1))
        {
            printf("Barang tidak ada \n");
            goto pilih_barang;
        }

    jumlah_barang:
        printf("Masukkan jumlah barang: ");
        scanf("%d", &banyak);
        jumlah[i] = banyak;

        if (banyak <= 0)
        {
            printf("Jumlah barang harus lebih dari 0\n");
            goto jumlah_barang;
        }

        total += banyak * harga[pilihan];

        i++;
        printf("Lanjut? [yes/no]: ");
        scanf("%s", &yes);
        int done = strcmp("yes", yes);

        if (done == 1)
        {
            break;
        }
    }

    printf("\n======= List Pembayaran =======\n");
    printf("%15s %7s %10s %10s\n", "Barang", "Jumlah", "Harga", "Total");
    for (j = 0; j < i; j++)
    {
        int total_harga = harga_dipilih[j] * jumlah[j];
        printf("%15s %7d %10d %10d\n", barang_dipilih[j], jumlah[j], harga_dipilih[j], total_harga);
    }

    printf("\nApakah anda memiliki kartu member? [yes/no]: ");
    scanf("%s", &isMember);
    int member = strcmp("yes", isMember);

    if (member == 0)
    {
        printf("\nAnda mendapatkan diskon sebesar 20%% \n");
        int diskon = total * 0.2;
        total = total - diskon;
        printf("total:\t%d\n\n", total);
        goto pembayaran;
    }
    else
    {
        printf("total:\t%d\n\n", total);
        goto pembayaran;
    }

pembayaran:
    printf("Masukkan uang: ");
    scanf("%d", &uang);
    if (uang < total)
    {
        printf("!===Uang kurang===!\n\n");
        goto pembayaran;
    }
    else
    {
        kembalian = uang - total;
        printf("Kembalian:     %d", kembalian);
        printf("\n======= Terima kasih sudah berbelanja =======\n");
    }

    return 0;
}
