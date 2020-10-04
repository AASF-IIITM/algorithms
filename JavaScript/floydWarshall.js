export default function floydWarshall(graph) {
  const vertices = graph.getAllVertices();
  
  const nextVertices = Array(vertices.length).fill(null).map(() => {
    return Array(vertices.length).fill(null);
  });

  const distances = Array(vertices.length).fill(null).map(() => {
    return Array(vertices.length).fill(Infinity);
  });

  vertices.forEach((startVertex, startIndex) => {
    vertices.forEach((endVertex, endIndex) => {
      if (startVertex === endVertex) {
        distances[startIndex][endIndex] = 0;
      } else {
        const edge = graph.findEdge(startVertex, endVertex);

        if (edge) {
          distances[startIndex][endIndex] = edge.weight;
          nextVertices[startIndex][endIndex] = startVertex;
        } else {
          distances[startIndex][endIndex] = Infinity;
        }
      }
    });
  });
  
  vertices.forEach((middleVertex, middleIndex) => {
    vertices.forEach((startVertex, startIndex) => {
      
      vertices.forEach((endVertex, endIndex) => {
        
        const distViaMiddle = distances[startIndex][middleIndex] + distances[middleIndex][endIndex];

        if (distances[startIndex][endIndex] > distViaMiddle) {
        
          distances[startIndex][endIndex] = distViaMiddle;
          nextVertices[startIndex][endIndex] = middleVertex;
        }
      });
    });
  });

  return { distances, nextVertices };
}
