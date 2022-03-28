
import pytest


def underweight():
  assert main.classifyBMI(18.4)=="underweight"
def normal():
  assert main.classifyBMI(18.6)=="underweight"
def overweight():
  assert main.classifyBMI(25.1)=="underweight"
def obese():
  assert main.classifyBMI(31.0)=="underweight"

