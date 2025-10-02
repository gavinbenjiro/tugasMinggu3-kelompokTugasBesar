#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BATAS_TOLERANSI 0.01

int toleransi_satu_persen(double x, double y) {
    if (x <= 0 || y <= 0) return 0;
    double rasio = fmax(x, y) / fmin(x, y);

    if (rasio <= 1.0 + BATAS_TOLERANSI) {
        return 1;
    } else {
        return 0;
    }
}

void klasifikasi_segitiga(double sisi_a, double sisi_b, double sisi_c, int mode_eksak) {
    double sisi_kcl, sisi_tgh, sisi_bsr;
    double temp_swap;

    sisi_kcl = sisi_a;
    sisi_tgh = sisi_b;
    sisi_bsr = sisi_c;

    if (sisi_kcl > sisi_tgh) { temp_swap = sisi_kcl; sisi_kcl = sisi_tgh; sisi_tgh = temp_swap; }
    if (sisi_tgh > sisi_bsr) { temp_swap = sisi_tgh; sisi_tgh = sisi_bsr; sisi_bsr = temp_swap; }
    if (sisi_kcl > sisi_tgh) { temp_swap = sisi_kcl; sisi_kcl = sisi_tgh; sisi_tgh = temp_swap; }

    if (sisi_kcl <= 0.0) {
        printf("Tidak ada segitiga dapat dibangun (Sisi harus positif).\n");
        return;
    }

    if (sisi_kcl + sisi_tgh <= sisi_bsr) {
        printf("Tidak ada segitiga dapat dibangun (Sisi terbesar lebih besar atau sama dengan jumlah dua sisi lainnya).\n");
        return;
    }

    if (mode_eksak) {
        long long bulat_kcl = (long long)sisi_kcl;
        long long bulat_tgh = (long long)sisi_tgh;
        long long bulat_bsr = (long long)sisi_bsr;

        if (bulat_kcl == bulat_tgh && bulat_tgh == bulat_bsr) {
            printf("Segitiga SAMA SISI (EQUILATERAL).\n");
        }
        else if (bulat_bsr * bulat_bsr == bulat_kcl * bulat_kcl + bulat_tgh * bulat_tgh) {
            printf("Segitiga SIKU-SIKU (RIGHT TRIANGLE).\n");
        }
        else if (bulat_kcl == bulat_tgh || bulat_tgh == bulat_bsr) {
            printf("Segitiga SAMA KAKI (ISOSCELES).\n");
        }
        else {
            printf("Segitiga BEBAS (SCALENE).\n");
        }

    } else {
        int kcl_tgh_sama = toleransi_satu_persen(sisi_kcl, sisi_tgh);
        int tgh_bsr_sama = toleransi_satu_persen(sisi_tgh, sisi_bsr);

        if (kcl_tgh_sama && tgh_bsr_sama) {
            printf("Segitiga SAMA SISI (EQUILATERAL).\n");
        }
        else if (toleransi_satu_persen(sisi_bsr * sisi_bsr, sisi_kcl * sisi_kcl + sisi_tgh * sisi_tgh)) {
            printf("Segitiga SIKU-SIKU (RIGHT TRIANGLE).\n");
        }
        else if (kcl_tgh_sama || tgh_bsr_sama) {
            printf("Segitiga SAMA KAKI (ISOSCELES).\n");
        }
        else {
            printf("Segitiga BEBAS (SCALENE).\n");
        }
    }
}

int main() {
    double a, b, c;
    int pilihan_mode;

    printf("Pilih mode perbandingan:\n");
    printf("1. Bilangan Bulat (Eksak)\n");
    printf("2. Bilangan Pecahan (Toleransi 1%%)\n");
    printf("Masukkan pilihan (1 atau 2): ");

    if (scanf("%d", &pilihan_mode) != 1) {
        printf("Masukan tidak valid.\n");
        return 1;
    }

    printf("\nMasukkan panjang sisi a, b, dan c: \n");
    printf("a: "); scanf("%lf", &a);
    printf("b: "); scanf("%lf", &b);
    printf("c: "); scanf("%lf", &c);

    printf("\nHasil:\n");

    if (pilihan_mode == 1) {
        klasifikasi_segitiga(a, b, c, 1);
    } else if (pilihan_mode == 2) {
        klasifikasi_segitiga(a, b, c, 0);
    } else {
        printf("Pilihan mode tidak valid.\n");
        return 1;
    }

    return 0;
}
