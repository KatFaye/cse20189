CMP = g++
MAIN = dataProcess
LANG = guessLanguage
JACC = jaccardSimilarity
PUZZ = main
FLAGS =  -std=c++11 -Wall -g

all: $(MAIN) $(LANG) $(JACC) $(PUZZ)

$(MAIN): $(MAIN).cpp
	$(CMP) -$(FLAGS) $^ -o $@

$(LANG): $(LANG).cpp
	$(CMP) -$(FLAGS) $^ -o $@

$(JACC): $(JACC).cpp
	$(CMP) -$(FLAGS) $^ -o $@

$(PUZZ): $(PUZZ).cpp
	$(CMP) -$(FLAGS) $^ -o $@

clean:
	rm $(MAIN) $(LANG) $(JACC) $(PUZZ) *.o *Out.txt