class TextEditor {
    public:
        string left, right;
    
        TextEditor() {
            left = "";
            right = "";
        }
    
        void addText(string text) {
            left += text; // Agrega el texto a la izquierda del cursor
        }
    
        int deleteText(int k) {
            int count = min(k, (int)left.size());
            left.erase(left.size() - count, count); // Borra los últimos count caracteres
            return count;
        }
    
        string cursorLeft(int k) {
            int moves = min(k, (int)left.size());
            // Mueve 'moves' caracteres desde left a right
            right = string(left.end() - moves, left.end()) + right;
            left.erase(left.size() - moves, moves);
            return left.substr(max(0, (int)left.size() - 10));
        }
    
        string cursorRight(int k) {
            int moves = min(k, (int)right.size());
            // Mueve 'moves' caracteres desde right a left
            left += right.substr(0, moves);
            right.erase(0, moves);
            return left.substr(max(0, (int)left.size() - 10));
        }
    };
    