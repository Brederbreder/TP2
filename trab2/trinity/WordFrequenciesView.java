package trinity;

import java.awt.Desktop;
import java.io.File;
import java.io.IOException;
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

public class WordFrequenciesView {
	private WordFrequenciesModel model;

	public WordFrequenciesView(WordFrequenciesModel model) {
		
		this.model = model;
	}

	public void render() { 
		LinkedHashMap<String, Integer> sorted_freqs = new LinkedHashMap<>();

		model.freqs
			.entrySet()
			.stream()
			.sorted(Map.Entry.comparingByValue(Comparator.reverseOrder())) 
			.forEachOrdered(x -> sorted_freqs.put(x.getKey(), x.getValue()));

		int count = 0;
		printloop:
		for (Map.Entry<String, Integer> entry : sorted_freqs.entrySet()) {
    		count++;
    		System.out.println("'" + entry.getKey() + "'" + ", " + entry.getValue().toString() + ")");
			
			if (count == 30)
				break printloop;
		}
	}

}