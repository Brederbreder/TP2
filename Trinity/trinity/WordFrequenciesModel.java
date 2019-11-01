package trinity;

import java.io.File;
import java.io.IOException;
import java.io.FileNotFoundException;
import java.nio.file.Files;
import java.util.ArrayList;
import java.util.List; 
import java.io.*;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;

public class WordFrequenciesModel {

	final static Map<String, Integer> freqs = new HashMap<>();

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
				this.freqs.merge(word, 1, Integer::sum);
			}

			System.out.print("\033[H\033[2J");  
			System.out.flush();

		} catch (FileNotFoundException e) {
			System.out.println("File not found!");
			this.freqs.clear();
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
