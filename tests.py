import pytest
from functions import *

#classifyBMI Test
def test_underweight():
    assert classifyBMI(18.4) == "underweight"
def test_normal():
    assert classifyBMI(18.6)=="normal"
def test_overweight():
  assert classifyBMI(25.1)=="overweight"
def test_obese():
  assert classifyBMI(31.0)=="obese"

