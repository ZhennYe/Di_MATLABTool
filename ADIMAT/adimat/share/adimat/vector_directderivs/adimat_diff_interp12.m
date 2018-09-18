function varargout = adimat_diff_interp12(varargin)
  [partial_2 varargout{2}] = partial_interp1_2(varargin{2}, varargin{4}, varargin{6});
  partial_3 = partial_interp1_3(varargin{2}, varargin{4}, varargin{6});
  varargout{1} = d_zeros(varargout{2});
  ndd = size(varargin{1}, 1);
  for d=1:ndd
    dd_2 = varargin{3}(d,:);
    dd_3 = varargin{5}(d,:);
    varargout{1}(d,:) = partial_2 * dd_2(:) + partial_3 * dd_3(:);
  end
end
% automatically generated from $Id: derivatives-vdd.xml 3983 2013-12-21 11:20:23Z willkomm $
