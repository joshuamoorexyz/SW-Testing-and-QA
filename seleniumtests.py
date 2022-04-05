import unittest
from selenium import webdriver
from selenium.webdriver.common.keys import Keys

class PythonOrgSearch(unittest.TestCase):

    def setUp(self):
        self.driver = webdriver.Firefox()

    def test_search_in_python_org(self):
        driver = self.driver
        driver.get("http://127.0.0.1:5000/")
        self.assertIn("BMI", driver.title)


    def tearDown(self):
        self.driver.close()

if __name__ == "__main__":
    unittest.main()
