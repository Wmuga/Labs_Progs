class meme_maker {
public:
    void black_screen_meme(char *, bool, char *, char *);

    meme_maker();

    void change_buffer_path(char *);

    void change_in_path(char *);

private:
    void get_font_lat();

    void get_font_cir();

    static void make_lat_text(char *, char *);

    static void make_cir_text(char *, char *);

    char *buffer_file_path = (char *) "..\\buffer\\";
    char *in_file_path = (char *) "..\\fonts\\";
    // use >> or << to fin correct letter
    static unsigned int cir_letters_array[6][5];
    static unsigned int lat_letters_array[6][5];
};