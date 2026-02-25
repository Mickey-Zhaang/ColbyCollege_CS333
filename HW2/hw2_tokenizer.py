# Identifier -> Letter { Letter | Digit }
# Letter -> a ... z | A .. Z
# Digit -> 0 | ... | 9
# Literal -> Integer | Boolean 
# Boolean -> true | false

# List of literal values
# if, while, else, ==, !=, ...
# ";"		{ echo (); return new Token (TokenClass . SEMICOLON); }
# "{"		{ echo (); return new Token (TokenClass . LBRACE); }
# "}"		{ echo (); return new Token (TokenClass . RBRACE); }
# "("		{ echo (); return new Token (TokenClass . LPAREN); }
# ")"		{ echo (); return new Token (TokenClass . RPAREN); }
# "["		{ echo (); return new Token (TokenClass . LBRACK); }
# "]"		{ echo (); return new Token (TokenClass . RBRACK); }
# "="		{ echo (); return new Token (TokenClass . ASSIGN); }
# "||"		{ echo (); return new Token (TokenClass . OR); }
# "&&"		{ echo (); return new Token (TokenClass . AND); }
# "+"		{ echo (); return new Token (TokenClass . PLUS); }
# "-"		{ echo (); return new Token (TokenClass . MINUS); }
# "*"		{ echo (); return new Token (TokenClass . TIMES); }
# "/"		{ echo (); return new Token (TokenClass . SLASH); }
# "%"		{ echo (); return new Token (TokenClass . MOD); }
# "=="		{ echo (); return new Token (TokenClass . EQ); }
# "!="		{ echo (); return new Token (TokenClass . NE); }
# "<"		{ echo (); return new Token (TokenClass . LT); }
# "<="		{ echo (); return new Token (TokenClass . LE); }
# ">"		{ echo (); return new Token (TokenClass . GT); }
# ">="		{ echo (); return new Token (TokenClass . GE); }

# The value field will always be a string. This makes it easier for the parsing.s

class Token:
    def __init__( self, value ):
        self.value = value
        
    def isInteger( self ):
        return False
        
    def __str__( self ):
        return str(self.value)
        
class IntegerToken(Token):        
    def isInteger( self ):
        return True
    def __str__( self ):
        return "int: " + str(self.value)
        
class Tokenizer:

    def __init__( self, string_to_parse ):
        self.string_to_parse = string_to_parse
        self.cur_index = 0
        
    # Increment the line and column indices until they indicate the
    # beginning of a token.
    def passWhitespace(self):
        # search this line for a non-whitespace character
        for self.cur_index in range(self.cur_index,len(self.string_to_parse)):
            if self.string_to_parse[self.cur_index] not in " \t\n\r":
                break
            
    def parseInt(self):
        """ advance the indices and return the int as an int"""
        b = self.cur_index
        for self.cur_index in range(b, len(self.string_to_parse)):
            if self.string_to_parse[self.cur_index] not in "0123456789":
                return IntegerToken( self.string_to_parse[b:self.cur_index] )
        if self.cur_index >= b:
            # we are at the end of the string. We didn't find a non-int character because there
            # isn't one to find
            self.cur_index += 1
            return IntegerToken( self.string_to_parse[b:] )
    
    def getToken(self):
        self.passWhitespace()
        if self.cur_index == len(self.string_to_parse):
            # We are at the end of the string. No more tokens
            return None
        cur_char  = self.string_to_parse[self.cur_index]
        if cur_char in "(+-)":
            self.cur_index += 1
            return Token( cur_char )
        elif cur_char in "0123456789":
            return self.parseInt()
        else:
            return None
        
if __name__ == '__main__':
    t = Tokenizer( '23+4')
    while True:
        tok = t.getToken()
        if tok is None:
            break
        print( tok )