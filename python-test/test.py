import unittest
import os
import filecmp
import subprocess

LEXER_PATH = "lexer/"
SYNTAX_PATH = "syntax/"
DECA_FILES_PATH = "deca_files/"
DECA_RESULTS_PATH = "result_files/"
DECA_TMP_PATH = "tmp_files/"
DECA_COMPILER_PATH = "../build/src/"

class LexerTest(unittest.TestCase):

    def setUp(self):
        if "main" not in os.listdir(DECA_COMPILER_PATH):
            raise ValueError('No binary found for deca compiler')

    def test_lexer(self):
        self.component_test(LEXER_PATH, "-l")

    def test_syntax(self):
        self.component_test(SYNTAX_PATH, "-p")

    def component_test(self, COMPONENT_PATH, COMPILER_OPTION):

        decafiles = [
            fname for fname in os.listdir(COMPONENT_PATH + DECA_FILES_PATH) 
            if fname.endswith('.deca')  
        ]
        resultfiles = [
            fname for fname in os.listdir(COMPONENT_PATH + DECA_RESULTS_PATH) 
            if fname.endswith('.txt')
        ]

        for fname in decafiles:
            tmp_result_file = open(
                COMPONENT_PATH + DECA_TMP_PATH + fname.split('.')[0]+'.txt',
                'w'
            )
            subprocess.call(
                [
                    DECA_COMPILER_PATH + "main", 
                    COMPONENT_PATH + DECA_FILES_PATH + fname, 
                    COMPILER_OPTION
                ],
                stdout = tmp_result_file
            )
        
        match = filecmp.cmpfiles(
            COMPONENT_PATH + DECA_RESULTS_PATH,
            COMPONENT_PATH + DECA_TMP_PATH,
            resultfiles
        )[0]

        for fname in resultfiles:
            print(fname)
            self.assertTrue(fname in match)

if __name__ == '__main__':
    unittest.main()