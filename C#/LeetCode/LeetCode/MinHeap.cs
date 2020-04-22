using System;
using System.Collections.Generic;
using System.Text;

namespace LeetCode
{
    class MinHeap
    {
        private int[] _elements;
        private int _size;

        public MinHeap(int size)
        {
            _elements = new int[size];
        }

        private int GetLeftChildIndex(int elementIdx) => 2 * elementIdx + 1;
        private int GetRightChildIndex(int elementIdx) => 2 * elementIdx + 2;
        private int GetParentIndex(int elementIdx) => (elementIdx - 1) / 2;

        private bool HasLeftChild(int elementIdx) => GetLeftChildIndex(elementIdx) < _size;
        private bool HasRightChild(int elementIdx) => GetRightChildIndex(elementIdx) < _size;
        private bool IsRoot(int elmenetIdx) => elmenetIdx == 0;

        private int GetLeftChild(int elementIdx) => _elements[GetLeftChildIndex(elementIdx)];
        private int GetRightChild(int elementIdx) => _elements[GetRightChildIndex(elementIdx)];
        private int GetParent(int elementIdx) => _elements[GetParentIndex(elementIdx)];

        private void Swap(int firstIndex, int secondIndex)
        {
            var temp = _elements[firstIndex];
            _elements[firstIndex] = _elements[secondIndex];
            _elements[secondIndex] = temp;
        }

        private void MinHeapify(int index)
        {
            int smallerIndex = index;

            if (HasLeftChild(index) && GetLeftChild(index) < _elements[index])
            {
                smallerIndex = GetLeftChildIndex(index);
            }

            if (HasRightChild(index) && GetRightChild(index) < _elements[smallerIndex])
            {
                smallerIndex = GetRightChildIndex(index);
            }

            if (smallerIndex != index)
            {
                Swap(smallerIndex, index);
                MinHeapify(smallerIndex);
            }
        }

        private void ReCalculate()
        {
            int i = _size - 1;
            // Fix the Min Heap property
            while (!IsRoot(i) && GetParent(i) > _elements[i])
            {
                Swap(i, GetParentIndex(i));
                i = GetParentIndex(i);
            }
        }

        public bool IsEmpty()
        {
            return _size == 0;
        }

        public int Peek()
        {
            if (_size == 0)
            {
                throw new IndexOutOfRangeException();
            }

            return _elements[0];
        }

        public int Pop()
        {
            if (_size == 0)
            {
                throw new IndexOutOfRangeException();
            }

            var result = _elements[0];
            _elements[0] = _elements[_size - 1];
            _size--;

            MinHeapify(0);

            return result;
        }

        public void Add(int element)
        {
            if (_size == _elements.Length)
            {
                throw new IndexOutOfRangeException();
            }

            _elements[_size] = element;
            _size++;

            ReCalculate();
        }

        public int Count()
        {
            return _size;
        }
    }
}
