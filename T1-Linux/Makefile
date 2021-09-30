# -----------------------
# Transparencias para TALF
#
# by F. de Sande <fsande@ull.es>
# date: 28.Ene.2008
# ---
##### User configurable options #####
LATEX    = latex
BIBTEX   = bibtex
PDFLATEX = pdflatex
DVIPS    = dvips
DVIPDF   = dvipdf
L2HTML   = latex2html
PLOT     = gnuplot

SRC      = T0_Conceptos_Basicos.tex
DVI	     = $(SRC:.tex=.dvi)
BIB	     = $(SRC:.tex=.bib)
PS	     = $(SRC:.tex=.ps)
SRCSIN   = $(SRC:.tex=)
### End User configurable options ###

default: all

all:
	$(MAKE) pdf

pdf: $(SRC) 
	$(PDFLATEX) $(SRC) && $(PDFLATEX) $(SRC);
	
html: $(PS)
	$(L2HTML) -dir HTML -split 4 -local_icons -long_titles 20 $(SRC)

ps: $(DVI)
	$(DVIPS) -o $(PS) $(DVI)
#	$(LATEX) $(SRC) && $(MAKE) bib && $(LATEX) $(SRC) && $(DVIPS) -o $(PS) $(DVI);

bib: $(SRC) $(BIB) 
	$(BIBTEX) $(SRCSIN)

clean:
	$(RM) *.vrb *.dvi *.bbl *.aux *.toc *.lof *.lot *.log *.blg *.out *~ basura* HTML/* *.nav *.snm

delete:
	$(MAKE) clean; $(RM) *~ $(SRCSIN).pdf $(SRCSIN).ps

%.dvi: %.tex
	$(LATEX) $(SRC) && $(MAKE) bib && $(LATEX) $(SRC) && $(LATEX) $(SRC)
	
# end
# --
