void dbg_out() { cerr << endl; }

const char* extract_file_name(const char* path) {
    const char* file = path;
    while (*path) {
        if (*path == '/' || *path == '\\') {
            file = path + 1;
        }
        path++;
    }
    return file;
}

template<typename Head, typename... Tail> 
void dbg_out(Head H, Tail... T) { 
	cerr << ' ' << H; dbg_out(T...); 
}

#define db(...) cerr << '[' << extract_file_name(__FILE__) << ':' \
                     << __LINE__ << "] (" << #__VA_ARGS__ \
                     << "):", dbg_out(__VA_ARGS__)
                     
                  