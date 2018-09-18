function varargout = adimat_diff_poly(varargin)
  [partial varargout{2}] = partial_poly(varargin{2});
  varargout{1} = d_zeros(varargout{2}(:).');
  argsz = size(varargin{2});
  ndd = size(varargin{1}, 1);
  for d=1:ndd
    dd = varargin{1}(d,:);
    varargout{1}(d,:) = partial * dd(:);
  end
end
% automatically generated from $Id: derivatives-vdd.xml 3983 2013-12-21 11:20:23Z willkomm $
