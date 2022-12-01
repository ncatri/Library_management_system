clean_data:
	cat livres.csv | cut -f3-6 -d ";" | grep -v "Article de REGLES"
