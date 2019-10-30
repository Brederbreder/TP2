package trinity;

import java.awt.Desktop;
import java.io.File;
import java.io.IOException;
import java.io.FileNotFoundException;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.util.ArrayList;
import java.util.List; 
import java.util.Scanner;
import java.io.*;
import java.lang.*;
import java.util.*;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.Map;
import java.util.Iterator;
import java.util.Set;

public class WordFrequenciesModel {

	final static Map<String, Integer> freqs = new TreeMap<>();

	public WordFrequenciesModel(String path_to_file) {
		this.update(path_to_file);
	}

	public void update(String fileName) {
		
		try {
			BufferedReader path = new BufferedReader(new FileReader(fileName));
			List<String> stop_words = new ArrayList<String>();
			List<String> all_words = new ArrayList<String>();

			stop_words = loadStopwords();
			String line = path.readLine();
						
			while (line != null) {
				String[] words = line.replaceAll("[^a-zA-Z ]", " ").toLowerCase().split("\\s+"); 
				for (String w : words) {
					if (!w.isEmpty())
						all_words.add(w);
				}

				line = path.readLine();
			}

			all_words.removeAll(stop_words);
			for (String word : all_words) {
				freqs.merge(word, 1, Integer::sum);
			}

		} catch (FileNotFoundException e) {
			System.out.println("File not found!");
			freqs.clear();
		} catch (IOException e) {}
	}

	public List<String> loadStopwords() {
    	List<String> stop_words = new ArrayList<String>();
		try {
			BufferedReader file = new BufferedReader(new FileReader("stop_words.txt"));

			String line = file.readLine();
			while (line != null) {
				for (String word : line.split(",")) {
					stop_words.add(word);
				}
				line = file.readLine();
			}

			file.close();
		} catch (IOException e) {}
	
		return stop_words;
	}

}