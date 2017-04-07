//
//  ViewController.swift
//  iOS_PassageCount_Display
//
//  Created by Damien Bannerot on 07/04/2017.
//  Copyright © 2017 Damien Bannerot. All rights reserved.
//

import UIKit
import Charts
import Alamofire

class ViewController: UIViewController {
	
	@IBOutlet weak var chartView: LineChartView!
	@IBOutlet weak var countLabel: UILabel!
	
	private final let restURL: String = "https://api.mlab.com/api/1/databases/presence_iot/collections/presences?apiKey=ZtfXpfvNfY99X41BE7DOwHLB8HXUyd-7&l=200&s={\"date\":-1}"
	
	var mlabDatas: [entry] = []
	var count: Int = 0 {
		didSet {
			self.countLabel.text = "\(count)"
		}
	}
	
	struct entry {
		var timestamp: Int
		var count: Int
	}
	
	override func viewDidLoad() {
		super.viewDidLoad()
		
		self.retrieveMongoData()
		Timer.scheduledTimer(timeInterval: 2, target: self, selector: #selector(ViewController.retrieveMongoData), userInfo: nil, repeats: true)
		
		self.chartView.noDataText = "aucune données."
		self.chartView.chartDescription?.text = ""//"température"
		self.chartView.animate(xAxisDuration: 0.4)
		self.chartView.animate(yAxisDuration: 0.4)
		
		/*
				var test: [entry] = []
				test.append(entry(timestamp: 1487890800, count: 0))
				test.append(entry(timestamp: 1487890830, count: 12))
				test.append(entry(timestamp: 1487890860, count: 1))
				test.append(entry(timestamp: 1487890890, count: 8))
				test.append(entry(timestamp: 1487890910, count: 18))
				test.append(entry(timestamp: 1487890940, count: 23))
				test.append(entry(timestamp: 1487890970, count: 19))
				test.append(entry(timestamp: 1487891000, count: 21))
				test.append(entry(timestamp: 1487891030, count: 7))
				test.append(entry(timestamp: 1487891060, count: 0))
				self.setChartView(entriesData: test)
		*/
		
	}
	
	override func didReceiveMemoryWarning() {
		super.didReceiveMemoryWarning()
		// Dispose of any resources that can be recreated.
	}
	
	func setChartView(entriesData: [entry]) {
		//print(entriesData)
		var chartEntries: [ChartDataEntry] = []
		var xStrings: [String] = []
		let sortedentriesData = entriesData.sorted { (s1: entry, s2: entry) -> Bool in
			return s1.timestamp < s2.timestamp
		}
		for (i, entry) in sortedentriesData.enumerated() {
			let newEntry = ChartDataEntry(x: Double(i), y: Double(entry.count))
			chartEntries.append(newEntry)
			let dateFormatter = DateFormatter()
			dateFormatter.timeStyle = .none
			dateFormatter.dateStyle = .short
			let timeFormatter = DateFormatter()
			timeFormatter.timeStyle = .medium
			timeFormatter.dateStyle = .none
//			if(i%10 == 0) {
//				xStrings.append("\(dateFormatter.string(from: Date.init(timeIntervalSince1970: TimeInterval(entry.timestamp))))\n\(timeFormatter.string(from: Date.init(timeIntervalSince1970: TimeInterval(entry.timestamp))))")
//			} else {
				xStrings.append("")
//			}
		}
		let set: LineChartDataSet = LineChartDataSet(values: chartEntries, label: "Passage count")
		set.setColor(NSUIColor.blue, alpha: CGFloat(1))
		set.circleColors = [NSUIColor.blue]
		set.circleRadius = 3
		set.mode = LineChartDataSet.Mode.linear
		
		let data: LineChartData = LineChartData(dataSet: set)
		self.chartView.xAxis.labelRotationAngle = -90
		self.chartView.xAxis.valueFormatter = DefaultAxisValueFormatter(block: {(index, _) in
			return xStrings[Int(index)]
		})
		self.chartView.xAxis.setLabelCount(xStrings.count, force: true)
		self.chartView.data = data
		self.chartView.notifyDataSetChanged()
	}
	
	func retrieveMongoData() {
		Alamofire.request(self.restURL.addingPercentEncoding(withAllowedCharacters: CharacterSet.urlQueryAllowed)!).responseJSON { response in
			//print(response);
			if let json = response.result.value {
				//print(json)
				self.mlabDatas = []
				if let array = json as? [[String:Any]] {
					//print(array)
					self.count = 0
					for dict in array {
						if let date = dict["date"] as? String, let count = dict["count"] {
							//print("\(date) \(count)")
							let dateFormatter = DateFormatter()
							dateFormatter.dateFormat = "yyyy-MM-dd HH:mm:ss.SSSSSS"
							let timestamp = dateFormatter.date(from: date)
							let verifiedDate: Int = Int(timestamp!.timeIntervalSince1970)
							let verifiedCount: Int = count as! Int//Int((count as! NSString).intValue)
							self.count += verifiedCount
							let test: entry = entry(timestamp: verifiedDate, count: verifiedCount)
							self.mlabDatas.append(test)
						}
					}
					
					self.setChartView(entriesData: self.mlabDatas)
				} else {
					print("not ok")
				}
			}
		}
	}
	
}
