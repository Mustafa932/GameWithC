#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#else
    #define CLEAR "clear"
#endif
#define MAX_DEGER 100
#define MIN_DEGER 0
#define MAX_DEGER_BECERI 25
#define MIN_DEGER_BECERI 3

// Maksimum degerleri kontrol eden bir fonksiyon
void sinirla(int* deger) {
    if (*deger > MAX_DEGER) {
        *deger = MAX_DEGER;
    }
    if (*deger < MIN_DEGER) {
        *deger = MIN_DEGER;
    }
}
void sinirla_beceri(int* deger) {
    if (*deger > MAX_DEGER_BECERI) {
        *deger = MAX_DEGER;
    }
    if (*deger < MIN_DEGER_BECERI) {
        *deger = MIN_DEGER_BECERI;
    }
}


typedef struct {
    char isim[50];
    char calgi[50];
    int para;
    int seviye;
    int tecrube;
    int can;
    int tokluk;
    int uyku;
    int hijyen;
    int guc;
    int ceviklik;
    int dayaniklilik;
    int karizma;
    int toplayicilik;
    int su;
    int ruh_hali;
    int yorgunluk;
} Ozan;

void durum_goster(Ozan ozan) {
    printf("isim: %s, calgi: %s, seviye: %d, tecrube: %d\n", ozan.isim, ozan.calgi, ozan.seviye, ozan.tecrube);
    printf("Can: %d, Tokluk: %d, Uyku: %d, Hijyen: %d, Para: %d\n", ozan.can, ozan.tokluk, ozan.uyku, ozan.hijyen, ozan.para);
    printf("Guc: %d, Ceviklik: %d, Dayaniklilik: %d, Karizma: %d, Toplayicilik: %d\n", ozan.guc, ozan.ceviklik, ozan.dayaniklilik, ozan.karizma, ozan.toplayicilik);
    printf("Su: %d, Ruh Hali: %d, Yorgunluk: %d\n", ozan.su, ozan.ruh_hali, ozan.yorgunluk);
}

void ana_menu(Ozan ozan) {
    printf("Merhaba, %s! Su anki durumun:\n", ozan.isim);
    durum_goster(ozan);
    printf("1. Kamp alanina git\n");
    printf("2. Sifahaneye git\n");
    printf("3. Hana git\n");
    printf("4. Maceraya atil\n");
    printf("5. Yeteneklerini gelistir\n");  // Yeni seçenek ekledik
    printf("6. Seviye atla\n");
    printf("7. Durumu goster\n");
    printf("8. Oyundan cik\n");
}


void kamp_alani(Ozan* ozan) {
    int secim;
    while (1) {
        printf("Kamp alanina hos geldiniz! Ne yapmak istersiniz?\n");
        printf("1. Kamp atesinin basinda calgi cal/sarki soyle\n");
        printf("2. Nehirde yikan\n");
        printf("3. Cadirina girip uyu\n");
        printf("4. Koy meydanina don\n");
        printf("Bir secenek giriniz: ");
        scanf("%d", &secim);

        system(CLEAR);

        // Tokluk ve uyku seviyesi sýfýrsa can kaybý uygulama
        int can_kaybi = 0;

        if (ozan->tokluk == 0) {
            can_kaybi += 20;  // Tokluk 0 ise can kaybý 20
            printf("Uyari: Tokluk seviyesi 0'a dustu! Can kaybettiniz: 20\n");
        }
        if (ozan->uyku == 0) {
            can_kaybi += 10;  // Uyku 0 ise can kaybý 10
            printf("Uyari: Uyku seviyesi 0'a dustu! Can kaybettiniz: 10\n");
        }

        // Eðer can kaybý olduysa caný azaltýyoruz
        ozan->can -= can_kaybi;
        if (ozan->can < 0) ozan->can = 0;

        // Kritik seviyelerdeki nitelikler için uyarýlar
        if (ozan->tokluk < 20) {
            printf("Uyari: Tokluk seviyesi kritik! (%d)\n", ozan->tokluk);
        }
        if (ozan->uyku < 20) {
            printf("Uyari: Uyku seviyesi kritik! (%d)\n", ozan->uyku);
        }
        if (ozan->hijyen < 20) {
            printf("Uyari: Hijyen seviyesi kritik! (%d)\n", ozan->hijyen);
        }
        if (ozan->su < 20) {
            printf("Uyari: Su seviyesi kritik! (%d)\n", ozan->su);
        }
        if (ozan->ruh_hali < 20) {
            printf("Uyari: Ruh hali seviyesi kritik! (%d)\n", ozan->ruh_hali);
        }
        if (ozan->yorgunluk > 80) {
            printf("Uyari: Yorgunluk seviyesi kritik! (%d)\n", ozan->yorgunluk);
        }

        // Kullanýcýya uyarýlarý göster
        printf("Can: %d, Uyku: %d, Tokluk: %d, Hijyen: %d, Su: %d, Yorgunluk: %d\n",
                ozan->can, ozan->uyku, ozan->tokluk, ozan->hijyen, ozan->su, ozan->yorgunluk);

        // Seçeneklere göre iþlemler
        if (secim == 1) {
            printf("Kamp atesinin basinda calgi caliyorsunuz...\n");
            ozan->uyku -= 10;   // Uyku azalýr
            ozan->tokluk -= 5;  // Tokluk azalýr
            ozan->karizma += 10; // Karizma artar
            ozan->yorgunluk += 5;  // Yorgunluk artar
            sinirla(&ozan->uyku);  // Maksimum 100 sýnýrýna çek
            sinirla(&ozan->tokluk); // Maksimum 100 sýnýrýna çek
            sinirla_beceri(&ozan->karizma); // Maksimum 100 sýnýrýna çek
            sinirla(&ozan->yorgunluk); // Maksimum 100 sýnýrýna çek
            printf("Uyku: %d, Tokluk: %d, Karizma: %d, Yorgunluk: %d\n", ozan->uyku, ozan->tokluk, ozan->karizma, ozan->yorgunluk);
        } else if (secim == 2) {
            printf("Nehirde yikaniyorsunuz...\n");
            ozan->uyku -= 5;    // Uyku azalýr
            ozan->tokluk -= 5;  // Tokluk azalýr
            ozan->hijyen += 20; // Hijyen artar
            ozan->su -= 10;     // Su azalýr
            ozan->yorgunluk += 5;  // Yorgunluk artar
            sinirla(&ozan->uyku);  // Maksimum 100 sýnýrýna çek
            sinirla(&ozan->tokluk); // Maksimum 100 sýnýrýna çek
            sinirla(&ozan->hijyen); // Maksimum 100 sýnýrýna çek
            sinirla(&ozan->su);     // Maksimum 100 sýnýrýna çek
            sinirla(&ozan->yorgunluk); // Maksimum 100 sýnýrýna çek
            printf("Uyku: %d, Tokluk: %d, Hijyen: %d, Su: %d, Yorgunluk: %d\n", ozan->uyku, ozan->tokluk, ozan->hijyen, ozan->su, ozan->yorgunluk);
        } else if (secim == 3) {
            printf("Cadiriniza girip uyuyorsunuz...\n");
            ozan->can += 10;    // Uyku caný iyileþtirir
            ozan->uyku = 100;   // Uyku yenilenir
            ozan->tokluk -= 5;  // Tokluk azalýr
            ozan->hijyen -= 5;  // Hijyen azalýr
            ozan->yorgunluk -= 10; // Yorgunluk azalýr
            sinirla(&ozan->can);  // Maksimum 100 sýnýrýna çek
            sinirla(&ozan->uyku);  // Maksimum 100 sýnýrýna çek
            sinirla(&ozan->tokluk); // Maksimum 100 sýnýrýna çek
            sinirla(&ozan->hijyen); // Maksimum 100 sýnýrýna çek
            sinirla(&ozan->yorgunluk); // Maksimum 100 sýnýrýna çek
            printf("Can: %d, Uyku: %d, Tokluk: %d, Hijyen: %d, Yorgunluk: %d\n", ozan->can, ozan->uyku, ozan->tokluk, ozan->hijyen, ozan->yorgunluk);
        } else if (secim == 4) {
            break; // Koy meydanýna dönülür, kamp bitirilir
        } else {
            printf("Gecersiz secenek, lutfen tekrar deneyin.\n");
        }
         if (ozan->can <= 0) {
            printf("Oldunuz!\n");
            exit(0);
        }
    }
}



void sifahane(Ozan* ozan) {
    int secim;
    while (1) {
        printf("Sifahaneye hos geldiniz! Ne yapmak istersiniz?\n");
        printf("1. Sifacidan yaralarini sarmasini iste\n");
        printf("2. Sifacidan merhem yapip surmesini iste\n");
        printf("3. Koy meydanina don\n");
        printf("Bir secenek giriniz: ");
        scanf("%d", &secim);

        system(CLEAR);
        if (secim == 1) {
            if (ozan->para >= 5) {
                printf("Sifaci yaralarinizi sarýyor...\n");
                ozan->can += 20;  // Yara sarma iyileþme saðlar
                sinirla(&ozan->can);  // Maksimum 100 sýnýrýna çek
                ozan->para -= 5;  // Para azalýr
                sinirla(&ozan->para);
            } else {
                printf("Yaralarinizi sarmak icin yeterli paraniz yok.\n");
            }
        } else if (secim == 2) {
            if (ozan->para >= 3) {
                printf("Sifaci size merhem yapip sürüyor...\n");
                ozan->can += 10;  // Merhem caný iyileþtirir
                sinirla(&ozan->can);  // Maksimum 100 sýnýrýna çek
                ozan->para -= 3;  // Para azalýr
                sinirla(&ozan->para);
            } else {
                printf("Merhem yapmak icin yeterli paraniz yok.\n");
            }
        } else if (secim == 3) {
            break;
        } else {
            printf("Gecersiz secenek, lutfen tekrar deneyin.\n");
        }
    }
}

void han(Ozan* ozan) {
    int secim;
    while (1) {
        printf("Hana hos geldiniz! Ne yapmak istersiniz?\n");
        printf("1. Yiyecek satin al ve ye\n");
        printf("2. Icecek satin al, ic ve eglen\n");
        printf("3. Enstruman cal ve sarki soyle\n");
        printf("4. Koy meydanina don\n");
        printf("Bir secenek giriniz: ");
        scanf("%d", &secim);

        system(CLEAR);
        if (secim == 1) {
            // Yiyecek menüsünü aç
            int yiyecek_secim;
            printf("Yiyecek alabileceðiniz menü:\n");
            printf("1. Ekmek (Tokluk +5, Fiyat: 5 para)\n");
            printf("2. Yahni (Tokluk +20, Fiyat: 10 para)\n");
            printf("3. Elma (Tokluk +10, Fiyat: 3 para)\n");
            printf("4. Çorba (Tokluk +15, Fiyat: 7 para)\n");
            printf("5. Makarna (Tokluk +12, Fiyat: 6 para)\n");
            printf("6. Izgara Tavuk (Tokluk +25, Fiyat: 15 para)\n");
            printf("Bir secenek giriniz: ");
            scanf("%d", &yiyecek_secim);

            if (yiyecek_secim == 1) {
                if (ozan->para >= 5) {
                    ozan->para -= 5;  // Para azalýr
                    ozan->tokluk += 5;  // Tokluk 5 artar
                    ozan->hijyen-=5;
                    sinirla(&ozan->hijyen);
                	ozan->ruh_hali+=5;
                	sinirla(&ozan->ruh_hali);
                	ozan->su-=5;
                	sinirla(&ozan->su);
                    if (ozan->tokluk > 100) ozan->tokluk = 100;  // Tokluk sýnýrlandýrýlýr
                    sinirla(&ozan->para);
                    printf("Ekmek yediniz! Tokluk: %d\n", ozan->tokluk);
                } else {
                    printf("Yiyecek almak icin yeterli paraniz yok.\n");
                }
            } else if (yiyecek_secim == 2) {
                if (ozan->para >= 10) {
                    ozan->para -= 10;  // Para azalýr
                    sinirla(&ozan->para);
                    ozan->tokluk += 20;  // Tokluk 20 artar
                    if (ozan->tokluk > 100) ozan->tokluk = 100;  // Tokluk sýnýrlandýrýlýr
                    ozan->hijyen-=5;
                    sinirla(&ozan->hijyen);
                	ozan->ruh_hali+=5;
                	sinirla(&ozan->ruh_hali);
                	ozan->su-=5;
                	sinirla(&ozan->su);
                    printf("Yahni yediniz! Tokluk: %d\n", ozan->tokluk);
                } else {
                    printf("Yiyecek almak icin yeterli paraniz yok.\n");
                }
            } else if (yiyecek_secim == 3) {
                if (ozan->para >= 3) {
                    ozan->para -= 3;  // Para azalýr
                    sinirla(&ozan->para);
                    ozan->tokluk += 10;  // Tokluk 10 artar
                    if (ozan->tokluk > 100) ozan->tokluk = 100;  // Tokluk sýnýrlandýrýlýr
                    ozan->hijyen-=5;
                    sinirla(&ozan->hijyen);
                	ozan->ruh_hali+=5;
                	sinirla(&ozan->ruh_hali);
                	ozan->su-=5;
                	sinirla(&ozan->su);
                    printf("Elma yediniz! Tokluk: %d\n", ozan->tokluk);
                } else {
                    printf("Yiyecek almak icin yeterli paraniz yok.\n");
                }
            } else if (yiyecek_secim == 4) {
                if (ozan->para >= 7) {
                    ozan->para -= 7;  // Para azalýr
                    sinirla(&ozan->para);
                    ozan->tokluk += 15;  // Tokluk 15 artar
                    if (ozan->tokluk > 100) ozan->tokluk = 100;  // Tokluk sýnýrlandýrýlýr
                    ozan->hijyen-=5;
                    sinirla(&ozan->hijyen);
                	ozan->ruh_hali+=5;
                	sinirla(&ozan->ruh_hali);
                	ozan->su-=5;
                	sinirla(&ozan->su);
                    printf("Corba ictiniz! Tokluk: %d\n", ozan->tokluk);
                } else {
                    printf("Yiyecek almak icin yeterli paraniz yok.\n");
                }
            } else if (yiyecek_secim == 5) {
                if (ozan->para >= 6) {
                    ozan->para -= 6;  // Para azalýr
                    sinirla(&ozan->para);
                    ozan->tokluk += 12;  // Tokluk 12 artar
                    if (ozan->tokluk > 100) ozan->tokluk = 100;  // Tokluk sýnýrlandýrýlýr
                    ozan->hijyen-=5;
                    sinirla(&ozan->hijyen);
                	ozan->ruh_hali+=5;
                	sinirla(&ozan->ruh_hali);
                	ozan->su-=5;
                	sinirla(&ozan->su);
                    printf("Makarnayi yediniz! Tokluk: %d\n", ozan->tokluk);
                } else {
                    printf("Yiyecek almak icin yeterli paraniz yok.\n");
                }
            } else if (yiyecek_secim == 6) {
                if (ozan->para >= 15) {
                    ozan->para -= 15;  // Para azalýr
                    sinirla(&ozan->para);
                    ozan->tokluk += 25;  // Tokluk 25 artar
                    if (ozan->tokluk > 100) ozan->tokluk = 100;  // Tokluk sýnýrlandýrýlýr
                    ozan->hijyen-=5;
                    sinirla(&ozan->hijyen);
                	ozan->ruh_hali+=5;
                	sinirla(&ozan->ruh_hali);
                	ozan->su-=5;
                	sinirla(&ozan->su);
                    printf("Izgara tavuk yediniz! Tokluk: %d\n", ozan->tokluk);
                } else {
                    printf("Yiyecek almak icin yeterli paraniz yok.\n");
                }
            } else {
                printf("Gecersiz secenek, lutfen tekrar deneyin.\n");
            }
        } else if (secim == 2) {
            // Ýçki menüsünü aç
            int icecek_secim;
            printf("Icecek alabileceðiniz menü:\n");
            printf("1. Su (Fiyat: 2 para)\n");
            printf("2. Meyve suyu (Fiyat: 5 para)\n");
            printf("3. Kahve (Fiyat: 4 para)\n");
            printf("4. Sýcak Çikolata (Fiyat: 6 para)\n");
            printf("5. Bira (Fiyat: 8 para)\n");
            printf("Bir secenek giriniz: ");
            scanf("%d", &icecek_secim);

            if (icecek_secim == 1) {
                if (ozan->para >= 2) {
                    ozan->para -= 2;  // Para azalýr
                    sinirla(&ozan->para);
                    ozan->hijyen-=5;
                    sinirla(&ozan->hijyen);
                	ozan->ruh_hali+=5;
                	sinirla(&ozan->ruh_hali);
                	ozan->su+=5;
                	sinirla(&ozan->su);
                    printf("Su içtiniz! Saðlýðýnýz iyileþti.\n");
                } else {
                    printf("Icecek almak icin yeterli paraniz yok.\n");
                }
            } else if (icecek_secim == 2) {
                if (ozan->para >= 5) {
                    ozan->para -= 5;  // Para azalýr
                    sinirla(&ozan->para);
                    ozan->hijyen-=5;
                    sinirla(&ozan->hijyen);
                	ozan->ruh_hali+=5;
                	sinirla(&ozan->ruh_hali);
                	ozan->su+=5;
                	sinirla(&ozan->su);
                    printf("Meyve suyu içtiniz! Saðlýðýnýz iyileþti.\n");
                } else {
                    printf("Icecek almak icin yeterli paraniz yok.\n");
                }
            } else if (icecek_secim == 3) {
                if (ozan->para >= 4) {
                    ozan->para -= 4;  // Para azalýr
                    sinirla(&ozan->para);
                    ozan->hijyen-=5;
                    sinirla(&ozan->hijyen);
                	ozan->ruh_hali+=5;
                	sinirla(&ozan->ruh_hali);
                	ozan->su+=5;
                	sinirla(&ozan->su);
                    printf("Kahve içtiniz! Kendinizi daha enerjik hissediyorsunuz.\n");
                } else {
                    printf("Icecek almak icin yeterli paraniz yok.\n");
                }
            } else if (icecek_secim == 4) {
                if (ozan->para >= 6) {
                    ozan->para -= 6;  // Para azalýr
                    sinirla(&ozan->para);
                    ozan->hijyen-=5;
                    sinirla(&ozan->hijyen);
                	ozan->ruh_hali+=5;
                	sinirla(&ozan->ruh_hali);
                	ozan->su+=5;
                	sinirla(&ozan->su);
                    printf("Sýcak çikolata içtiniz! Kendinizi rahatlamýþ hissediyorsunuz.\n");
                } else {
                    printf("Icecek almak icin yeterli paraniz yok.\n");
                }
            } else if (icecek_secim == 5) {
                if (ozan->para >= 8) {
                    ozan->para -= 8;  // Para azalýr
                    sinirla(&ozan->para);
                    ozan->hijyen-=5;
                    sinirla(&ozan->hijyen);
                	ozan->ruh_hali+=5;
                	sinirla(&ozan->ruh_hali);
                	ozan->su+=5;
                	sinirla(&ozan->su);
                    printf("Bira içtiniz! Kendinizi daha rahat hissediyorsunuz.\n");
                } else {
                    printf("Icecek almak icin yeterli paraniz yok.\n");
                }
            } else {
                printf("Gecersiz secenek, lutfen tekrar deneyin.\n");
            }
        } else if (secim == 3) {
            // Enstrüman çal ve þarký söyle
            if (ozan->hijyen <= 20) {
                printf("Hijyen seviyeniz cok dusuk. Sarký soyleyemezsiniz.\n");
            } else {
                printf("Enstrüman calip sarki soyluyorsunuz...\n");
                ozan->karizma += 1;  // Karizma artar
                sinirla_beceri(&ozan->karizma);
                int kazanc = 10 + (ozan->karizma * ozan->hijyen) / 100;
                ozan->para += kazanc;  // Kazanç eklenir
                ozan->tecrube+=20;
                printf("Kazandiginiz para: %d. Toplam para: %d\n", kazanc, ozan->para);
            }
        } else if (secim == 4) {
            break;  // Koy meydanýna dönülür
        } else {
            printf("Gecersiz secenek, lutfen tekrar deneyin.\n");
        }
         if (ozan->can <= 0) {
            printf("Oldunuz!\n");
            exit(0);
        }
    }
}



int savas(Ozan* ozan, int dusman_guc, int dusman_ceviklik, int dusman_dayaniklilik) {
    int ozan_can = ozan->can;
    int dusman_can = 100;  // Haydutun baslangic cani
    int ozan_guc = ozan->guc;
    int ozan_ceviklik = ozan->ceviklik;
    int ozan_dayaniklilik = ozan->dayaniklilik;

    printf("Dusmanin gucu: %d, Cevikligi: %d, Dayanikliligi: %d\n", dusman_guc, dusman_ceviklik, dusman_dayaniklilik);

    // Ozan ile dusmanin hangi turda saldiracagini belirle
    int turn = (ozan_ceviklik > dusman_ceviklik) ? 1 : (ozan_ceviklik == dusman_ceviklik ? rand() % 2 + 1 : 2);

    while (ozan_can > 0 && dusman_can > 0) {
        int ozan_hasar = 4 * ozan_guc;
        int dusman_hasar = 4 * dusman_guc;

        if (turn == 1) {  // Ozan saldirdi
            int alinan_hasar = dusman_hasar - (dusman_hasar * (4 * ozan_dayaniklilik / 100.0) - 1);
            dusman_can -= alinan_hasar;
            printf("Ozan saldirdi! Dusmanin cani: %d, Ozanin cani: %d\n", dusman_can, ozan_can);
            turn = 2;
        } else {  // Dusman saldirdi
            int alinan_hasar = ozan_hasar - (ozan_hasar * (4 * dusman_dayaniklilik / 100.0) - 1);
            ozan_can -= alinan_hasar;
            printf("Dusman saldirdi! Dusmanin cani: %d, Ozanin cani: %d\n", dusman_can, ozan_can);
            turn = 1;
        }

        if (dusman_can <= 0) {
            printf("Dusman oldu! Kazandiniz!\n");
            ozan->tecrube += 50;
            ozan->para += 10;
            return 1;  // Ozan kazandi
        }
        if (ozan_can <= 0) {
            printf("Ozan oldu! Kaybettiniz!\n");
            exit(0);  // Ozan kaybetti
        }

        // Kullanýcýya her saldýrýdan sonra kaçma mý dövüþ mü sorulacak
        int secim_savas;
        while (1) {
            printf("Haydut karsiniza cikti! Kaçmak (1) veya Savaþmak (2) istiyor musunuz?\n");
            scanf("%d", &secim_savas);

            if (secim_savas == 1) {
                if (kacar_mi(ozan->ceviklik)) {
                    printf("Basarili bir sekilde kacabildiniz!\n");
                    break;
                } else {
                    printf("Kacmak basarisiz oldu! Savas basliyor...\n");
                    break;
                }
            } else if (secim_savas == 2) {
                break;  // Dövüþe baþla
            } else {
                printf("Gecersiz secenek, lutfen tekrar deneyin.\n");
            }
        }
    }
    return 0;
}



int kacar_mi(int ceviklik) {
    // Kaçma olasýlýðý = %4 * (ceviklik / 100)
    return rand() % 100 < 4 * (ceviklik / 100);
}

void yagma_yap(Ozan* ozan, char* kesif_turu) {
    int ganimet = 0;
    int galip_gelme_durum = rand() % 2;  // %50 sansla galip gelme durumu (0 = kayip, 1 = galip)

    // Kesif turune gore ganimet araligini belirle
    if (galip_gelme_durum == 1) {  // Eger galip geldiyse
        if (strcmp(kesif_turu, "kolay") == 0) {
            ganimet = rand() % 11 + 15;  // Kolay kesif: 15-25 altin
        } else if (strcmp(kesif_turu, "orta") == 0) {
            ganimet = rand() % 21 + 30;  // Orta kesif: 30-50 altin
        } else if (strcmp(kesif_turu, "zor") == 0) {
            ganimet = rand() % 21 + 55;  // Zor kesif: 55-75 altin
        }

        // Ganimeti kullaniciya ekleyelim
        ozan->para += ganimet;
        sinirla(&ozan->para);  // Altin miktarini 100 ile sinirla
        printf("Kesif basarili! Kazandiginiz ganimet: %d altin\n", ganimet);
    } else {
        printf("Kesif basarisiz oldu! Ganimet kazanamadiniz.\n");
    }
}

void macera(Ozan* ozan) {
    int secim;
    while (1) {
        printf("Maceraya atilmaya hazir misiniz? Ne yapmak istersiniz?\n");
        printf("1. Yakin cevrede sifali bitki topla ve avlan\n");
        printf("2. Ormani kesfe cik (kolay)\n");
        printf("3. Kayaliklari kesfe cik (orta)\n");
        printf("4. Zorlu dusmanla savasa gir (zor)\n");
        printf("5. Koy meydanina don\n");
        printf("Bir secenek giriniz: ");
        scanf("%d", &secim);

        system(CLEAR);
        if (secim == 1) {
			    printf("Yakin cevrede sifali bitki topluyorsunuz...\n");

			    // Þifalý bitki bulma þansý hesaplanýyor
			    int sifali_bilgi_bulma_sansi = (ozan->toplayicilik * 4) / 100;
			    int rastgele_sayi = rand() % 100;

			    // Þifalý bitki bulunma durumu
			    if (rastgele_sayi < sifali_bilgi_bulma_sansi) {
			        ozan->can += 10;  // Þifalý bitki bulunursa can artar
			        printf("Þifalý bitki buldunuz! Canýnýz 10 arttý.\n");
			    }

			    // Meyve toplama þansý
			    if (rastgele_sayi < sifali_bilgi_bulma_sansi) {
			        ozan->tokluk += 10;  // Meyve toplama sonucu tokluk artar
			        printf("Meyve topladýnýz! Tokluðunuz 10 arttý.\n");

			        // Av hayvaný avlama þansý
			        if (rand() % 2 == 0) {  // Yarý þansla avlanma
			            ozan->tokluk += 50;  // Avlanan hayvanla tokluk artar
			            printf("Av hayvaný avladýnýz! Tokluðunuz 50 arttý.\n");
			        }
			    }

		    // Ozan'ýn diðer özellikleri güncelleniyor
		    ozan->para += 5;  // Para kazanýlýr
		    sinirla(&ozan->para);
		    ozan->tecrube += 10;  // Tecrübe kazanýlýr
		    sinirla_beceri(&ozan->tecrube);
		    ozan->tokluk -= 5;
		    sinirla(&ozan->tokluk);
		    ozan->su -= 4;
		    sinirla(&ozan->su);
		    ozan->hijyen -= 5;
		    sinirla(&ozan->hijyen);
		    ozan->uyku -= 5;
		    sinirla(&ozan->uyku);
		    ozan->yorgunluk += 10;
		    sinirla(&ozan->yorgunluk);
		}
        else if (secim == 2) {
            printf("Ormani gezintiye cikiyorsunuz...\n");
            ozan->tokluk -= 4;
            sinirla(&ozan->tokluk);
            ozan->su -= 2;
            sinirla(&ozan->su);
            ozan->hijyen -= 4;
            sinirla(&ozan->hijyen);
            ozan->uyku -= 4;
            sinirla(&ozan->uyku);
            ozan->yorgunluk += 5;
            sinirla(&ozan->yorgunluk);
            ozan->ruh_hali += 10;
            sinirla(&ozan->ruh_hali);
            ozan->tecrube += 30;

            // Kesif sonucu haydutlar karsisina cikacak
            int dusman_guc = rand() % 3 + 1;  // 1-3 guc
            int dusman_ceviklik = rand() % 3 + 1;  // 1-3 ceviklik
            int dusman_dayaniklilik = rand() % 3 + 1;  // 1-3 dayaniklilik

            // Kullaniciya kacma veya savasma seceneði sunulacak
            int secim_savas;
            while (1) {
                printf("Haydut karsiniza cikti! Kaçmak (1) veya Savaþmak (2) istiyor musunuz?\n");
                scanf("%d", &secim_savas);

                if (secim_savas == 1) {
                    if (kacar_mi(ozan->ceviklik)) {
                        printf("Basarili bir sekilde kacabildiniz!\n");
                        break;
                    } else {
                        printf("Kacmak basarisiz oldu! Savas basliyor...\n");
                        break;
                    }
                } else if (secim_savas == 2) {
                    // Savas simule et
                    int sonuc = savas(ozan, dusman_guc, dusman_ceviklik, dusman_dayaniklilik);
                    if (sonuc == 0) {
                        printf("Savasi kaybettiniz, odeme yapilamadi!\n");
                        break;
                    }
                    break;
                } else {
                    printf("Gecersiz secenek, lutfen tekrar deneyin.\n");
                }
            }
        } else if (secim == 3) {
            printf("Kayaliklari kesfe cikiyorsunuz...\n");
            ozan->tokluk -= 4;
            sinirla(&ozan->tokluk);
            ozan->su -= 2;
            sinirla(&ozan->su);
            ozan->hijyen -= 4;
            sinirla(&ozan->hijyen);
            ozan->uyku -= 4;
            sinirla(&ozan->uyku);
            ozan->yorgunluk += 5;
            sinirla(&ozan->yorgunluk);
            ozan->ruh_hali += 10;
            sinirla(&ozan->ruh_hali);
            ozan->tecrube += 60;

            // Kayaliklarda kesif
            yagma_yap(ozan, "orta");

            // Kullanýcýya "Kaçmak" veya "Savaþmak" seçeneði sunulacak
            int secim_savas;
            while (1) {
                printf("Haydut karsiniza cikti! Kaçmak (1) veya Savaþmak (2) istiyor musunuz?\n");
                scanf("%d", &secim_savas);

                if (secim_savas == 1) {
                    if (kacar_mi(ozan->ceviklik)) {
                        printf("Basarili bir sekilde kacabildiniz!\n");
                        break;
                    } else {
                        printf("Kacmak basarisiz oldu! Savas basliyor...\n");
                        break;
                    }
                } else if (secim_savas == 2) {
                    // Savas simule et
                    int dusman_guc = rand() % 3 + 4;  // 1-3 guc
                    int dusman_ceviklik = rand() % 3 + 4;  // 1-3 ceviklik
                    int dusman_dayaniklilik = rand() % 3 + 4;  // 1-3 dayaniklilik
                    int sonuc = savas(ozan, dusman_guc, dusman_ceviklik, dusman_dayaniklilik);
                    if (sonuc == 0) {
                        printf("Savasi kaybettiniz, odeme yapilamadi!\n");
                        break;
                    }
                    break;
                } else {
                    printf("Gecersiz secenek, lutfen tekrar deneyin.\n");
                }
            }
        } else if (secim == 4) {
            printf("Zorlu dusmanla savasa giriyorsunuz...\n");
            ozan->can -= 50;  // Can azalir
            ozan->tecrube += 50;  // Tecrube kazanilir
            ozan->para -= 10;  // Para azalir
            ozan->tecrube += 90;
            yagma_yap(ozan, "zor");

            // Kullanýcýya "Kaçmak" veya "Savaþmak" seçeneði sunulacak
            int secim_savas;
            while (1) {
                printf("Haydut karsiniza cikti! Kaçmak (1) veya Savaþmak (2) istiyor musunuz?\n");
                scanf("%d", &secim_savas);

                if (secim_savas == 1) {
                    if (kacar_mi(ozan->ceviklik)) {
                        printf("Basarili bir sekilde kacabildiniz!\n");
                        break;
                    } else {
                        printf("Kacmak basarisiz oldu! Savas basliyor...\n");
                        break;
                    }
                } else if (secim_savas == 2) {
                    // Savas simule et
                    int dusman_guc = rand() % 4 + 7;  // 1-3 guc
                    int dusman_ceviklik = rand() % 4 + 7;  // 1-3 ceviklik
                    int dusman_dayaniklilik = rand() % 4 + 7;  // 1-3 dayaniklilik
                    int sonuc = savas(ozan, dusman_guc, dusman_ceviklik, dusman_dayaniklilik);
                    if (sonuc == 0) {
                        printf("Savasi kaybettiniz, odeme yapilamadi!\n");
                        break;
                    }
                    break;
                } else {
                    printf("Gecersiz secenek, lutfen tekrar deneyin.\n");
                }
            }
        } else if (secim == 5) {
            break;
        } else {
            printf("Gecersiz secenek, lutfen tekrar deneyin.\n");
        }

        // Ozan'in cani 0'a duserse oyun bitiyor
        if (ozan->can <= 0) {
            printf("Oldunuz!\n");
            exit(0);
        }
    }
}




void yetenek_gelistir16(Ozan* ozan) {
    int secim;
    printf("Yeteneklerini gelistir: Hangi yetenegi gelistirmek istersiniz?\n");
    printf("1. Guclu ol\n");
    printf("2. Cevik ol\n");
    printf("3. Dayanikliligini arttir\n");
    printf("Bir secenek giriniz: ");
    scanf("%d", &secim);

    if (secim == 1) {
        // Güç artýrma
        printf("Guclu olmak icin agir tasi kaldiriyorsunuz. Bu islem yorucu olabilir.\n");
        printf("Güç kazanmak için birkaç dakika boyunca taþ kaldýrmak istiyorsunuz. Hazýr mýsýnýz? (E/H): ");
        char hazir_misiniz;
        scanf(" %c", &hazir_misiniz);

        if (hazir_misiniz == 'E' || hazir_misiniz == 'e') {
            ozan->guc += 1;  // Güç artýrýlýr
            ozan->tokluk -= 10;  // Tokluk azalýr
            ozan->uyku -= 5;     // Uyku azalýr
            printf("Gucunuz 1 arttirildi! Simdiki guc: %d\n", ozan->guc);
            printf("Tokluk: %d, Uyku: %d\n", ozan->tokluk, ozan->uyku);
            printf("Bu egzersiz yorucu oldu. Tokluk ve uyku seviyeniz azaldý.\n");
        } else {
            printf("Egzersizi yapmaktan vazgectiniz.\n");
        }

    } else if (secim == 2) {
        // Çeviklik artýrma
        printf("Cevik olmak icin hizli kosmak ve ziplamak gerekiyor. Hazir misiniz? (E/H): ");
        char hazir_misiniz;
        scanf(" %c", &hazir_misiniz);

        if (hazir_misiniz == 'E' || hazir_misiniz == 'e') {
            ozan->ceviklik += 1;  // Çeviklik artýrýlýr
            ozan->tokluk -= 5;    // Tokluk azalýr
            ozan->hijyen -= 10;   // Hijyen azalýr (Terleme sonucu hijyen kaybý)
            printf("Cevikliginiz 1 arttirildi! Simdiki ceviklik: %d\n", ozan->ceviklik);
            printf("Tokluk: %d, Hijyen: %d\n", ozan->tokluk, ozan->hijyen);
            printf("Hizli kosma ve ziplama sonucu biraz terlediniz, hijyeniniz azaldý.\n");
        } else {
            printf("Cevik olmak icin egzersizi yapmaktan vazgectiniz.\n");
        }

    } else if (secim == 3) {
        // Dayanýklýlýk artýrma
        printf("Dayanikli olmak icin zorlu bir egzersiz yapmanýz gerekiyor. Hazir misiniz? (E/H): ");
        char hazir_misiniz;
        scanf(" %c", &hazir_misiniz);

        if (hazir_misiniz == 'E' || hazir_misiniz == 'e') {
            ozan->dayaniklilik += 1;  // Dayanýklýlýk artýrýlýr
            ozan->uyku -= 15;         // Uyku azalýr (Egzersiz sonrasý yorgunluk)
            ozan->hijyen -= 5;        // Hijyen azalýr (Yorgunluk ve terleme)
            printf("Dayanikliliginiz 1 arttirildi! Simdiki dayaniklilik: %d\n", ozan->dayaniklilik);
            printf("Uyku: %d, Hijyen: %d\n", ozan->uyku, ozan->hijyen);
            printf("Zorlu egzersiz sonrasý biraz yoruldunuz ve hijyeniniz azaldý.\n");
        } else {
            printf("Dayanikli olmak icin egzersizi yapmaktan vazgectiniz.\n");
        }

    } else {
        printf("Gecersiz secenek.\n");
    }
}

void yetenek_gelistir(Ozan* ozan) {
    int secim;
    int beceri_puan = 5;  // Kullanýcýya verilecek beceri puaný

    printf("Seviye atladiniz! Harcayabileceginiz 5 beceri puaniniz var.\n");
    printf("Gecici becerileri gelistirebilirsiniz:\n");
    printf("1. Gucluk: %d\n", ozan->guc);
    printf("2. Ceviklik: %d\n", ozan->ceviklik);
    printf("3. Dayaniklilik: %d\n", ozan->dayaniklilik);
    printf("4. Karizma: %d\n", ozan->karizma);
    printf("5. Toplayicilik: %d\n", ozan->toplayicilik);

    while (beceri_puan > 0) {
        printf("\nKalan beceri puaniniz: %d\n", beceri_puan);
        printf("Bir beceri secin ve arttirmak icin '1' ile '5' arasinda secim yapin (Exit icin 0): ");
        scanf("%d", &secim);

        if (secim == 0) break;  // çýkýþ

        if (secim == 1 && beceri_puan > 0) {
            ozan->guc++;
            beceri_puan--;
            printf("Guc arttirildi! Yeni deger: %d\n", ozan->guc);
        } else if (secim == 2 && beceri_puan > 0) {
            ozan->ceviklik++;
            beceri_puan--;
            printf("Ceviklik arttirildi! Yeni deger: %d\n", ozan->ceviklik);
        } else if (secim == 3 && beceri_puan > 0) {
            ozan->dayaniklilik++;
            beceri_puan--;
            printf("Dayaniklilik arttirildi! Yeni deger: %d\n", ozan->dayaniklilik);
        } else if (secim == 4 && beceri_puan > 0) {
            ozan->karizma++;
            beceri_puan--;
            printf("Karizma arttirildi! Yeni deger: %d\n", ozan->karizma);
        } else if (secim == 5 && beceri_puan > 0) {
            ozan->toplayicilik++;
            beceri_puan--;
            printf("Toplayicilik arttirildi! Yeni deger: %d\n", ozan->toplayicilik);
        } else {
            printf("Gecersiz secim veya beceri puaniniz yok!\n");
        }
    }

    // Beceri puanlarý sýfýrlanacak ve ana menüye dönecek
    ozan->tecrube = 0;
    printf("Beceri puanlari basariyla harcandi. Ana menuye donuyorsunuz.\n");
}

void seviye_atla(Ozan* ozan) {
    if (ozan->tecrube >= 100) {
        ozan->seviye++;
        ozan->tecrube = 0;
        printf("Tebrikler! Seviye atladiniz! Yeni seviyeniz: %d\n", ozan->seviye);
        printf("Yeni beceri puanlariniz verildi. Yeteneklerinizi gelistirmenizi bekliyoruz...\n");
        yetenek_gelistir(ozan);  // Yetenek geliþtirme menüsüne geçiþ
    }
}





int main() {
    Ozan ozan;
    printf("Ozanin adini giriniz: ");
    fgets(ozan.isim, 50, stdin);
    ozan.isim[strcspn(ozan.isim, "\n")] = '\0'; // '\n' karakterini temizle
    printf("Ozanin calgi aletini giriniz: ");
    fgets(ozan.calgi, 50, stdin);
    ozan.calgi[strcspn(ozan.calgi, "\n")] = '\0'; // '\n' karakterini temizle

    ozan.para = 10;
    ozan.seviye = 1;
    ozan.tecrube = 0;
    ozan.can = 100;
    ozan.tokluk = 100;
    ozan.uyku = 100;
    ozan.hijyen = 100;
    ozan.guc = 3;
    ozan.ceviklik = 3;
    ozan.dayaniklilik = 3;
    ozan.karizma = 3;
    ozan.toplayicilik = 3;
    ozan.su = 100;
	ozan.ruh_hali = 100;
	ozan.yorgunluk = 0;

    int secim;
    while (1) {
    	if (ozan.tecrube >= 100) {
            printf("Tecrube puaniniz 100'e ulasti. Seviye atlama menüsüne gidiyorsunuz...\n");
            seviye_atla(&ozan);  // Seviye atla fonksiyonunu çaðýr
            continue;  // Seviye atlama iþleminden sonra ana menüyü geç
        }
        ana_menu(ozan);
        printf("Bir secenek giriniz: ");
        scanf("%d", &secim);

        system(CLEAR);
        if (secim == 1) {
            printf("Kamp alanina gidiyorsunuz...\n");
            kamp_alani(&ozan);
        } else if (secim == 2) {
            printf("Sifahaneye gidiyorsunuz...\n");
            sifahane(&ozan);
        } else if (secim == 3) {
            printf("Hana gidiyorsunuz...\n");
            han(&ozan);
        } else if (secim == 4) {
            printf("Maceraya atiliyorsunuz...\n");
            macera(&ozan);
        } else if (secim == 5) {
            printf("Yeteneklerinizi geliþtiriyorsunuz...\n");
            yetenek_gelistir(&ozan);  // Yeni fonksiyon çaðrýldý
        } else if (secim == 6) {
            printf("Seviye atliyorsunuz...\n");
            // Seviye atlama fonksiyonlari burada cagrilacak
        } else if (secim == 7) {
            durum_goster(ozan);
        } else if (secim == 8) {
            char emin_misiniz;
            printf("Oyundan cikmak istediginize emin misiniz? (E/H): ");
            scanf(" %c", &emin_misiniz);
            if (emin_misiniz == 'E' || emin_misiniz == 'e') {
                break;
            }
        } else {
            printf("Gecersiz secenek, lutfen tekrar deneyin.\n");
        }
    }

    return 0;
}
