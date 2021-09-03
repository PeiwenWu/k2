

#ifndef K2_PYTHON_CSRC_TORCH_V2_DOC_RAGGED_SHAPE_H_
#define K2_PYTHON_CSRC_TORCH_V2_DOC_RAGGED_SHAPE_H_
namespace k2 {

static constexpr const char *kRaggedShapeInitStr = R"doc(
Construct a ragged shape from a string.

An example string for a ragged shape with 2 axes is::

  [ [x x] [ ] [x] ]

An example string for a ragged shape with 3 axes is::

  [ [[x] []] [[x] [x x]] ]

>>> import k2.ragged as k2r
>>> shape = k2r.RaggedShape('[ [x] [] [x x] ]')
>>> shape
[ [ x ] [ ] [ x x ] ]
>>> shape2 = k2r.RaggedShape('[ [[x] [] [x x]] [[]] ]')
>>> shape2
[ [ [ x ] [ ] [ x x ] ] [ [ ] ] ]
)doc";

static constexpr const char *kRaggedShapeDim0Doc = R"doc(
Return number of sublists at axis 0.

>>> import k2.ragged as k2r
>>> shape = k2r.RaggedShape('[ [x] [] [x x x x x]]')
>>> shape.dim0
3
>>> shape2 = k2r.RaggedShape('[ [[x] []] [[]] [[x] [x x] [x x x]] [[]]]')
>>> shape2.dim0
4
)doc";

static constexpr const char *kRaggedShapeMaxSizeDoc = R"doc(
Return the maximum number of elements of any sublist at the given axis.

>>> import k2.ragged as k2r
>>> shape = k2r.RaggedShape('[ [] [x] [x x] [x x x] [x x x x] ]')
>>> shape.max_size(1)
4
>>> shape = k2r.RaggedShape('[ [[x x] [x] [] [] []] [[x]] [[x x x x]] ]')
>>> shape.max_size(1)
5
>>> shape.max_size(2)
4

Args:
  axis:
    Compute the max size of this axis.

    Caution:
      ``axis`` has to be greater than 0.

Returns:
  Return the maximum number of elements of sublists at the given ``axis``.
)doc";

static constexpr const char *kRaggedShapeNumelDoc = R"doc(
Return the number of elements in this shape.

>>> import k2.ragged as k2r
>>> shape = k2r.RaggedShape('[ [x] [] [x x x x x]]')
>>> shape.numel()
6
>>> shape2 = k2r.RaggedShape('[ [[x x] [x] [] [] []] [[x]] [[x x x x]] ]')
>>> shape2.numel()
8
>>> shape3 = k2r.RaggedShape('[ [x x x] [x] ]')
>>> shape3.numel()
4

Returns:
  Return the number of elements in this shape.

  Hint:
    It's the number of ``x``'s.
)doc";

static constexpr const char *kRaggedShapeTotSizeDoc = R"doc(
Return the number of elements at a certain``axis``.

>>> import k2.ragged as k2r
>>> shape = k2r.RaggedShape('[ [x] [x x] [x x x] []]')
>>> shape.tot_size(1)
6
>>> shape.numel()
6
>>> shape2 = k2r.RaggedShape('[ [[x]] [[x x]] [[x x x]] [[]] [[]] [[]] [[]] ]')
>>> shape2.tot_size(1)
7
>>> shape2 = k2r.RaggedShape('[ [[x]] [[x x]] [[x x x]] [[]] [[]] [[]] [[] []] ]')
>>> shape2.tot_size(1)
8
>>> shape2.tot_size(2)
6
>>> shape2.numel()
6

Args:
  axis:
    Return the number of elements for this ``axis``.

Returns:
  Return the number of elements at ``axis``.
)doc";

static constexpr const char *kRaggedShapeToDeviceDoc = R"doc(
Move this shape to the specified device.

Hint:
  If the shape is already on the specified device, the returned shape
  shares the underlying memory with ``self``.

>>> import k2.ragged as k2r
>>> shape = k2r.RaggedShape('[[x]]')
>>> shape.device
device(type='cpu')
>>> import torch
>>> shape2 = shape.to(torch.device('cuda', 0))
>>> shape2.device
device(type='cuda', index=0)
>>> shape
[ [ x ] ]
>>> shape2
[ [ x ] ]

Args:
  device:
    An instance of ``torch.device``. It can be either a CPU device or
    a CUDA device.
Returns:
  Return a shape on the given device.
)doc";

static constexpr const char *kRaggedShapeRowIdsDoc = R"doc(
Return the row ids of a certain ``axis``.

>>> import k2.ragged as k2r
>>> shape = k2r.RaggedShape('[ [x x] [] [x x x] ]')
>>> shape.row_ids(1)
tensor([0, 0, 2, 2, 2], dtype=torch.int32)
>>> shape2 = k2r.RaggedShape('[ [[x] [] [x x]] [[x x x] [x] [x x x x] [] []] ]')
>>> shape2.row_ids(1)
tensor([0, 0, 0, 1, 1, 1, 1, 1], dtype=torch.int32)
>>> shape2.row_ids(2)
tensor([0, 2, 2, 3, 3, 3, 4, 5, 5, 5, 5], dtype=torch.int32)

Args:
  axis:
    The axis whose row ids is to be returned.

  Hint:
    ``axis >= 1``.

Returns:
  Return the row ids of the given ``axis``.
)doc";

static constexpr const char *kRaggedShapeRowSplitsDoc = R"doc(
Return the row splits of a certain ``axis``.

>>> import k2.ragged as k2r
>>> shape = k2r.RaggedShape('[ [x x] [] [x x x] ]')
>>> shape.row_splits(1)
tensor([0, 2, 2, 5], dtype=torch.int32)
>>> shape2 = k2r.RaggedShape('[ [[x] [] [x x]] [[x x x] [x] [x x x x] [] []] ]')
>>> shape2.row_splits(1)
tensor([0, 3, 8], dtype=torch.int32)
>>> shape2.row_splits(2)
tensor([ 0,  1,  1,  3,  6,  7, 11, 11, 11], dtype=torch.int32)

Args:
  axis:
    The axis whose row splits is to be returned.

  Hint:
    ``axis >= 1``.

Returns:
  Return the row splits of the given ``axis``.
)doc";

static constexpr const char *kRaggedShapeTotSizesDoc = R"doc(
Return total sizes of every axis in a tuple.

>>> import k2.ragged as k2r
>>> shape = k2r.RaggedShape('[ [x] [ ] [x x x x]]')
>>> shape.dim0
3
>>> shape.tot_size(1)
5
>>> shape.tot_sizes()
(3, 5)
>>> shape2 = k2r.RaggedShape('[ [[x] []] [[x x x x]]]')
>>> shape2.dim0
2
>>> shape2.tot_size(1)
3
>>> shape2.tot_size(2)
5
>>> shape2.tot_sizes()
(2, 3, 5)

Returns:
  Return a tuple containing the total sizes of each axis.
  ``ans[i]`` is the total size of axis ``i`` (for ``i > 0``).
  For ``i=0``, it is the ``dim0`` of this shape.
)doc";

static constexpr const char *kRaggedShapeEqDoc = R"doc(
Return ``True`` if two shapes are equal. Otherwise, return ``False``.

Caution:
  The two shapes have to be on the same device. Otherwise, it throws
  an exception.

>>> import k2.ragged as k2r
>>> shape1 = k2r.RaggedShape('[ [] [x] ]')
>>> shape2 = k2r.RaggedShape('[ [x] [x] ]')
>>> shape3 = k2r.RaggedShape('[ [x] [x] ]')
>>> shape1 == shape2
False
>>> shape3 == shape2
True

Args:
  other:
    The shape that we want to compare with ``self``.
Returns:
  Return ``True`` if the two shapes are the same.
  Return ``False`` otherwise.
)doc";

static constexpr const char *kRaggedShapeNeDoc = R"doc(
Return ``True`` if two shapes are not equal. Otherwise, return ``False``.

Caution:
  The two shapes have to be on the same device. Otherwise, it throws
  an exception.

>>> import k2.ragged as k2r
>>> shape1 = k2r.RaggedShape('[ [] [x] ]')
>>> shape2 = k2r.RaggedShape('[ [x] [x] ]')
>>> shape3 = k2r.RaggedShape('[ [x] [x] ]')
>>> shape1 != shape2
True
>>> shape2 != shape3
False

Args:
  other:
    The shape that we want to compare with ``self``.
Returns:
  Return ``True`` if the two shapes are not equal.
  Return ``False`` otherwise.
)doc";

static constexpr const char *kRaggedShapeStrDoc = R"doc(
Return a string representation of this shape.

>>> import k2.ragged as k2r
>>> shape = k2r.RaggedShape('[ [x] [] [x x ] ]')
>>> print(shape)
[ [ x ] [ ] [ x x ] ]
>>> shape
[ [ x ] [ ] [ x x ] ]

)doc";

static constexpr const char *kRaggedShapeGetItemDoc = R"doc(
Select the i-th sublist along axis 0.

Note:
  It requires that this shape has at least 3 axes.

>>> import k2.ragged as k2r
>>> shape = k2r.RaggedShape('[ [[x] [x x]] [[x x x] [] [x x]] ]')
>>> shape[0]
[ [ x ] [ x x ] ]
>>> shape[1]
[ [ x x x ] [ ] [ x x ] ]

Args:
  i:
    The i-th sublist along axis 0.
Returns:
  Return a new ragged shape with one fewer axis.
)doc";

static constexpr const char *kRaggedShapeNumAxesDoc = R"doc(
Return the number of axes of this shape.

>>> import k2.ragged as k2r
>>> shape = k2r.RaggedShape('[[] []]')
>>> shape.num_axes
2
>>> shape2 = k2r.RaggedShape('[ [[]] [[]]]')
>>> shape2.num_axes
3
)doc";

static constexpr const char *kRaggedShapeDeviceDoc = R"doc(
Return the device of this shape.

>>> import k2.ragged as k2r
>>> shape = k2r.RaggedShape('[[]]')
>>> shape.device
device(type='cpu')
>>> import torch
>>> shape2 = shape.to(torch.device('cuda', 0))
>>> shape2.device
device(type='cuda', index=0)

)doc";

static constexpr const char *kRaggedShapeRegularDoc = R"doc(
Create a ragged shape with 2 axes that has a regular structure.

>>> import k2.ragged as k2r
>>> shape1 = k2r.RaggedShape.regular_ragged_shape(dim0=2, dim1=3)
>>> shape1
[ [ x x x ] [ x x x ] ]
>>> shape2 = k2r.regular_ragged_shape(dim0=3, dim1=2)
>>> shape2
[ [ x x ] [ x x ] [ x x ] ]

Args:
  dim0:
    Number of entries at axis 0.
  dim1:
    Number of entries in each sublist at axis 1.

Returns:
  Return a ragged shape on CPU.
)doc";

static constexpr const char *kRaggedShapeRemoveAxisDoc = R"doc(
Remove a certain axis.

Caution:
  ``self.num_axes`` MUST be greater than 2.

>>> import k2.ragged as k2r
>>> shape = k2r.RaggedShape('[ [[x] [] [x x]] [[x x x] [x x x x]] [[] [] []]]')
>>> shape.remove_axis(0)
[ [ x ] [ ] [ x x ] [ x x x ] [ x x x x ] [ ] [ ] [ ] ]
>>> shape.remove_axis(1)
[ [ x x x ] [ x x x x x x x ] [ ] ]

Args:
  axis:
    The axis to be removed.

Returns:
  Return a ragged shape with one fewer axis.
)doc";

static constexpr const char *kRaggedShapeComposeDoc = R"doc(
Compose ``self`` with a given shape.

Caution:
  ``other`` and ``self`` MUST be on the same device.

Hint:
  In order to compose ``self`` with ``other``, it has to
  satisfy ``self.tot_size(self.num_axes - 1) == other.dim0``

**Example 1**:

  >>> import k2.ragged as k2r
  >>> shape1 = k2r.RaggedShape('[ [x x] [x] ]')
  >>> shape2 = k2r.RaggedShape('[ [x x x] [x x] [] ]')
  >>> shape1.compose(shape2)
  [ [ [ x x x ] [ x x ] ] [ [ ] ] ]

**Example 2**:

  >>> import k2.ragged as k2r
  >>> shape1 = k2r.RaggedShape('[ [[x x] [x x x] []] [[x] [x x x x]] ]')
  >>> shape2 = k2r.RaggedShape('[ [x] [x x x] [] [] [x x] [x] [] [x x x x] [] [x x] ]')
  >>> shape1.compose(shape2)
  [ [ [ [ x ] [ x x x ] ] [ [ ] [ ] [ x x ] ] [ ] ] [ [ [ x ] ] [ [ ] [ x x x x ] [ ] [ x x ] ] ] ]
  >>> shape1.tot_size(shape1.num_axes - 1)
  10
  >>> shape2.dim0
  10

Args:
  other:
    The other shape that is to be composed with ``self``.

Returns:
  Return a composed ragged shape.
)doc";

static constexpr const char *kRaggedShapeGetLayerDoc = R"doc(
Returns a `sub-shape` of ``self``.

  >>> import k2.ragged as k2r
  >>> shape = k2r.RaggedShape('[ [[x x] [x] []] [[] [x x x] [x]] [[]] ]')
  >>> shape.get_layer(0)
  [ [ x x x ] [ x x x ] [ x ] ]
  >>> shape.get_layer(1)
  [ [ x x ] [ x ] [ ] [ ] [ x x x ] [ x ] [ ] ]

Args:
  layer:
    Layer that is desired, from ``0 .. src.num_axes - 2`` (inclusive).

Returns:
  This returned shape will have ``num_axes == 2``, the minimal case of
  a :class:`RaggedShape`.
)doc";

static constexpr const char *kRaggedShapeIndexDoc = R"doc(
Indexing operation on a ragged shape, returns ``self[indexes]``, where elements
of ``indexes`` are interpreted as indexes into axis ``axis`` of self``.

Caution:
  ``indexes`` is a 1-D tensor and ``indexes.dtype == torch.int32``.

**Example 1**:

  >>> import torch
  >>> import k2.ragged as k2r
  >>> shape = k2r.RaggedShape('[ [x x] [x] [x x x]]')
  >>> i = torch.tensor([0, 2, 1], dtype=torch.int32)
  >>> shape.index(0, i)
  [ [ x x ] [ x x x ] [ x ] ]
  >>> k = torch.tensor([0, -1, 1, 0, 2, -1], dtype=torch.int32)
  >>> shape.index(0, k)
  [ [ x x ] [ ] [ x ] [ x x ] [ x x x ] [ ] ]

**Example 2**:

  >>> import torch
  >>> import k2.ragged as k2r
  >>> shape = k2r.RaggedShape('[ [[x x] [x]] [[] [x x x] [x]] [[x] [] [] [x x]] ]')
  >>> i = torch.tensor([0, 1, 3, 5, 7, 8], dtype=torch.int32)
  >>> shape.index(axis=1, indexes=i)
  [ [ [ x x ] [ x ] ] [ [ x x x ] ] [ [ x ] [ ] [ x x ] ] ]

Args:
  axis:
    The axis to be indexed. Must satisfy ``0 <= axis < self.num_axes``.
  indexes:
    Array of indexes, which will be interpreted as indexes into axis ``axis``
    of ``self``, i.e. with ``0 <= indexes[i] < self.tot_size(axis)``.
    Note that if ``axis`` is 0, then -1 is also a valid entry in ``index``,
    in which case, an empty list is returned.

    Caution:
      It is currently not allowed to change the order on axes less than
      ``axis``, i.e. if ``axis > 0``, we require:
      ``IsMonotonic(self.row_ids(axis)[indexes])``.

Returns:
  Return an indexed ragged shape.
)doc";

}  // namespace k2

#endif  // K2_PYTHON_CSRC_TORCH_V2_DOC_RAGGED_SHAPE_H_
