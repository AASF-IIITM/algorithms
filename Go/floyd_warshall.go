package main

import (
	"fmt"
	"math"
)

type Matrix [][]float64

var maxValue = math.Inf(1)

func FloydWarshall(graph Matrix) Matrix {
	if len(graph) == 0 || len(graph) != len(graph[0]) {
		return nil
	}

	numVertecies := len(graph)

	result := make(Matrix, numVertecies)

	for i := 0; i < numVertecies; i++ {
		result[i] = make([]float64, numVertecies)
		for j := 0; j < numVertecies; j++ {
			result[i][j] = graph[i][j]
		}
	}

	for k := 0; k < numVertecies; k++ {
		for i := 0; i < numVertecies; i++ {
			for j := 0; j < numVertecies; j++ {
				if result[i][j] > result[i][k]+result[k][j] {
					result[i][j] = result[i][k] + result[k][j]
				}
			}
		}
	}

	return result
}

func main() {
	var graph Matrix
	graph = Matrix{{0, maxValue, -2, maxValue},
		{4, 0, 3, maxValue},
		{maxValue, maxValue, 0, 2},
		{maxValue, -1, maxValue, 0}}

	result := FloydWarshall(graph)

	for i := 0; i < len(result); i++ {
		fmt.Printf("%4g\n", result[i])
	}
}
